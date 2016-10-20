#include <iostream>
#include "../heaps/priorityheap.h"
#include "../heaps/binaryheap.h"
#include "../heaps/minmaxheap.h"

template <size_t number>
class Int 
{
public:
    static int comparisons;

    Int<number>(int x = 0) : val{x} {}
    
    int get_val() const { 
        return val; 
    }

    bool operator>(const Int<number>& other) const {
        Int<number>::comparisons++;
        return val > other.val;
    }

    bool operator<(const Int<number>& other) const {
        Int<number>::comparisons++;
        return val < other.val;
    }

private:
    int val;
};

template <size_t number> 
int Int<number>::comparisons = 0;

void run_test_on(const char* test_file) 
{
    size_t start_time = clock();
    printf("Running test in the file: %s\n", test_file);
    freopen(test_file, "r", stdin);

    int queries, adds, extrs;
    scanf("%d %d %d", &queries, &adds, &extrs);
    printf("The test consists of %d queries(adds=%d, extrs=%d)\n", queries, adds, extrs);

    std::unique_ptr<Heap<Int<1>>> priorityheap {new PriorityHeap<Int<1>>};
    int priorityheap_insert = 0, priorityheap_extract = 0;
    Int<1>::comparisons = 0;

    std::unique_ptr<Heap<Int<2>>> binaryheap {new BinaryHeap<Int<2>>};
    int binaryheap_insert = 0, binaryheap_extract = 0;
    Int<2>::comparisons = 0;

    std::unique_ptr<Heap<Int<3>>> minmaxheap {new MinMaxHeap<Int<3>>};
    int minmaxheap_insert = 0, minmaxheap_extract = 0;
    Int<3>::comparisons = 0;

    for (size_t i = 0; i < queries; i++) {
        int type;
        scanf("%d", &type);
        if (type == 0) {
            int x;
            scanf("%d", &x);

            priorityheap_insert -= clock();
            priorityheap->insert(Int<1>(x));
            priorityheap_insert += clock();

            binaryheap_insert -= clock();
            binaryheap->insert(Int<2>(x));
            binaryheap_insert += clock();

            minmaxheap_insert -= clock();
            minmaxheap->insert(Int<3>(x));
            minmaxheap_insert += clock();
        } else {
            priorityheap_extract-= clock();
            int e1 = priorityheap->extract_min().get_val();
            priorityheap_extract += clock();

            binaryheap_extract-= clock();
            int e2 = binaryheap->extract_min().get_val();
            binaryheap_extract += clock();

            minmaxheap_extract-= clock();
            int e3 = minmaxheap->extract_min().get_val();
            minmaxheap_extract += clock();

            if (e1 != e2 || e2 != e3) {
                printf("Incorrect result on the query #%d: %d %d %d\n", (int)i, e1, e2, e3);
                fprintf(stderr, "Test from %s has proved incorrectness. Finishing testing.\n", test_file);
                exit(0);
            }
        }
    }

    printf("The test successfully passed in %.3f\n", static_cast<double>(clock() - start_time) / CLOCKS_PER_SEC);

    printf("%-15s%-15s%-15s%-15s\n", "Results", "PriorityHeap", "BinaryHeap", "MinMaxHeap");
    printf("%-15s%-15d%-15d%-15d\n", "Comparisons:",
           Int<1>::comparisons,
           Int<2>::comparisons,
           Int<3>::comparisons);
    printf("%-15s%-15.3f%-15.3f%-15.3f\n", "Insert time:",
           static_cast<double>(priorityheap_insert) / CLOCKS_PER_SEC,
           static_cast<double>(binaryheap_insert) / CLOCKS_PER_SEC,
           static_cast<double>(minmaxheap_insert) / CLOCKS_PER_SEC);
    printf("%-15s%-15.3f%-15.3f%-15.3f\n", "Extract time:",
           static_cast<double>(priorityheap_extract) / CLOCKS_PER_SEC,
           static_cast<double>(binaryheap_extract) / CLOCKS_PER_SEC,
           static_cast<double>(minmaxheap_extract) / CLOCKS_PER_SEC);
    printf("\n");
    fprintf(stderr, "Test from %s has been finished.\n", test_file);
}

int main(int argc, char* argv[]) 
{
    freopen(argv[argc - 1], "w", stdout);
    for (size_t i = 1; i + 1 < argc; i++) {
        run_test_on(argv[i]);
    }
    fprintf(stderr, "Finished. Check logs in %s.\n", argv[argc - 1]);
}

