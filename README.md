INTRODUCTION.
This project compares different binary heaps, such as priority_queue, self written binary and MinMax.

STRUCTURE.
The section describes files in the project.

./Makefile
Has following targets: runtests, generator, tester, clean.

./heaps/heap.h
The pure abstract class Heap provides a common interface for the heaps. 

./heaps/priorityheap.h
The priory_queue heap implementation.

./heaps/binaryheap.h
The self written binary heap implementation.

./heaps/minmaxheap.h
The MinMax heap implementation.

To use any of them you just need to include a necessary header.

./src/generator.cpp
Helps you with test generation. Just run make generator and then use it in this way:
./generator file_for_output number_of_insertion_operations number_of_extraction_operations
Note that you must provide reasonable arguments, i.e. number_of_insertion_operations > number_of_extraction_operations. 

./src/runtests.sh
The script is used in runtests target. It concatenates the names of all files in ./tests/ directory and runs ./tester.

./src/tester.cpp
Run make tester. Usage: ./tester test_file_1 test_file_2 ... test_file_n results_file
It creates the heaps and checks their outputs(assuming that priority_heap is correct). Makes the results_file with
logs in an awesome format. This tester uses the clock() function and the CLOCKS_PER_SEC constant to measure time.

./tests/
Directory used for looking up tests.

./results.txt
Contains the results after testing.

RESEARCH.
The standard tests were generated in the following way:
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/01 10000000 0
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/02 10000000 0
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/03 9000000 1000000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/04 9000000 1000000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/05 8000000 2000000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/06 8000000 2000000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/07 7500000 2500000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/08 7500000 2500000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/09 5000000 5000000
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ ./generator tests/10 5000000 5000000
Also there is the special test - 11-th. It contains 10000000 insert queries which values are in descending order.

Then the tester was doing its work there:
ksaz@Sazanovichs-MacBook-Pro:~/Projects/heap_comparisons$ make
cc -std=c++11  src/tester.cpp -o tester
bash src/runtests.sh
Test from tests/01 has been finished.
Test from tests/02 has been finished.
Test from tests/03 has been finished.
Test from tests/04 has been finished.
Test from tests/05 has been finished.
Test from tests/06 has been finished.
Test from tests/07 has been finished.
Test from tests/08 has been finished.
Test from tests/09 has been finished.
Test from tests/10 has been finished.
Test from tests/11 has been finished.
Test from tests/12 has been finished.
Finished. Check logs in results.txt.

The results are:
niksaz@Sazanovichs-MacBook-Pro:~/Projects/heaps$ cat results.txt 
Running test in the file: tests/01
The test consists of 10000000 queries(adds=10000000, extrs=0)
The test successfully passed in 26.929
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   22824721       22824721       24392272       
Insert time:   4.731          4.308          4.990          
Extract time:  0.000          0.000          0.000          

Running test in the file: tests/02
The test consists of 10000000 queries(adds=10000000, extrs=0)
The test successfully passed in 27.963
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   22813198       22813198       24387822       
Insert time:   4.916          4.472          5.170          
Extract time:  0.000          0.000          0.000          

Running test in the file: tests/03
The test consists of 10000000 queries(adds=9000000, extrs=1000000)
The test successfully passed in 29.284
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   77784747       77784747       92021042       
Insert time:   4.488          4.046          4.602          
Extract time:  1.095          1.062          1.307          

Running test in the file: tests/04
The test consists of 10000000 queries(adds=9000000, extrs=1000000)
The test successfully passed in 29.098
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   77784663       77784663       92021510       
Insert time:   4.469          4.020          4.576          
Extract time:  1.088          1.058          1.299          

Running test in the file: tests/05
The test consists of 10000000 queries(adds=8000000, extrs=2000000)
The test successfully passed in 31.358
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   130991815      130991815      156695756      
Insert time:   4.284          3.810          4.221          
Extract time:  2.097          2.056          2.492          

Running test in the file: tests/06
The test consists of 10000000 queries(adds=8000000, extrs=2000000)
The test successfully passed in 31.543
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   130981133      130981133      156687204      
Insert time:   4.303          3.829          4.242          
Extract time:  2.111          2.068          2.519          

Running test in the file: tests/07
The test consists of 10000000 queries(adds=7500000, extrs=2500000)
The test successfully passed in 32.432
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   156038817      156038817      186955757      
Insert time:   4.206          3.709          4.040          
Extract time:  2.575          2.538          3.082          

Running test in the file: tests/08
The test consists of 10000000 queries(adds=7500000, extrs=2500000)
The test successfully passed in 32.651
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   156016884      156016884      186957694      
Insert time:   4.240          3.732          4.067          
Extract time:  2.594          2.552          3.105          

Running test in the file: tests/09
The test consists of 10000000 queries(adds=5000000, extrs=5000000)
The test successfully passed in 28.367
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   127799259      127799259      154075555      
Insert time:   2.683          2.347          2.301          
Extract time:  3.258          3.041          3.486          

Running test in the file: tests/10
The test consists of 10000000 queries(adds=5000000, extrs=5000000)
The test successfully passed in 29.083
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   143648992      143648992      172703144      
Insert time:   2.770          2.414          2.361          
Extract time:  3.395          3.200          3.681          

Running test in the file: tests/11
The test consists of 10000000 queries(adds=10000000, extrs=0)
The test successfully passed in 32.321
Results        PriorityHeap   BinaryHeap     MinMaxHeap     
Comparisons:   213222809      213222809      114407606      
Insert time:   7.717          6.560          6.379          
Extract time:  0.000          0.000          0.000          

Now it is clear that the best way to extract minimal element and inserting new ones in practice is a self written binary heap. 
Nevertheless, MinMaxHeap wins when an input is in descending order, because it climbs with double speed, thus making less comparisons and spending less time. It is demonstrated in the last log.
Also the interesting thing here is that the standard PriorityHeap and the self written BinaryHeap make the equal number of comparisons.
