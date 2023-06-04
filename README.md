# bruhst

```
benching rs
timing ./build.sh
getting number from ./deps.sh
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main

benching c
timing ./build.sh
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main

benching cc
timing ./build.sh
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main
timing ./main

>>> leaderboard <<<

1. c ( 0.4601764678955078 s to compile, 0 dependencies, 1.2762893915176392 runtime on average, syntax noise 0.17436770428015563 and bin file size of 6056 bytes )
2. cc ( 0.7707672119140625 s to compile, 0 dependencies, 1.1842130303382874 runtime on average, syntax noise 0.17442143727162 and bin file size of 7872 bytes )
3. rs ( 20.62468671798706 s to compile, 2 dependencies, 1.3575071334838866 runtime on average, syntax noise 0.18710388536786993 and bin file size of 408792 bytes )
```

-   c for life
-   c++ > rust in compile time, dependencies, syntax noise and bin size
-   rust > c++ in runtime ( although if ur not doing threaded computation, even that its barely significant )

# running bruhst urself

```sh
python3 bench.py
```

# what does it test

-   threading iteration ( threading, iteration, math, cast )
-   file io ( buffering )
-   fib ( recursion and conditions )
-   sort ( iteration, conditions, memory )
-   n-body simulation ( math, structures, iteration )

# requirements

-   cargo
-   python3
-   clang ( both clang and clang++ )
-   lld
