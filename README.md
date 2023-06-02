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

1. c ( 0.24728131294250488 s to compile, 0 dependencies, 1.7481301069259643 runtime on average, syntax noise 0.1763327475102519 and bin file size of 5616 bytes )
2. cc ( 0.6897192001342773 s to compile, 0 dependencies, 1.8984646677970887 runtime on average, syntax noise 0.17640152626944525 and bin file size of 7544 bytes )
3. rs ( 12.195837259292603 s to compile, 2 dependencies, 1.7413506269454957 runtime on average, syntax noise 0.1883594499520307 and bin file size of 390480 bytes )
```

-   c for life
-   c++ > rs in compile time, dependencies, syntax noise and binary size
-   rs > c++ in runtime

# running bruhst urself

```sh
python3 bench.py
```
