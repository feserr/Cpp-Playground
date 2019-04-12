# Performance outputs
## Dynamic interface perf output

```bash
Dynamic interface performance test.
 Performance counter stats for './crtp-performance d':

       1654,298400      task-clock (msec)         #    1,000 CPUs utilized
                 9      context-switches          #    0,005 K/sec
                 0      cpu-migrations            #    0,000 K/sec
                98      page-faults               #    0,059 K/sec
     5.613.354.192      cycles                    #    3,393 GHz
     2.411.850.992      stalled-cycles-frontend   #   42,97% frontend cycles idle
     7.205.488.507      instructions              #    1,28  insn per cycle
                                                  #    0,33  stalled cycles per insn
     2.400.972.526      branches                  # 1451,354 M/sec
            70.520      branch-misses             #    0,00% of all branches

       1,654729420 seconds time elapsed

       1,654656000 seconds user
       0,000000000 seconds sys
```

## Dynamic interface inline perf output

```bash
Dynamic interface inline performance test.
 Performance counter stats for './crtp-performance di':

       1418,833189      task-clock (msec)         #    1,000 CPUs utilized
                10      context-switches          #    0,007 K/sec
                 0      cpu-migrations            #    0,000 K/sec
                96      page-faults               #    0,068 K/sec
     4.812.428.025      cycles                    #    3,392 GHz
     3.211.194.009      stalled-cycles-frontend   #   66,73% frontend cycles idle
     5.605.189.498      instructions              #    1,16  insn per cycle
                                                  #    0,57  stalled cycles per insn
     1.600.973.843      branches                  # 1128,374 M/sec
            68.146      branch-misses             #    0,00% of all branches

       1,419212714 seconds time elapsed

       1,419131000 seconds user
       0,000000000 seconds sys
```

## CRTP interface perf output

```bash
CRTP interface performance test.
 Performance counter stats for './crtp-performance c':

       1654,824747      task-clock (msec)         #    1,000 CPUs utilized
                 2      context-switches          #    0,001 K/sec
                 0      cpu-migrations            #    0,000 K/sec
                98      page-faults               #    0,059 K/sec
     5.607.823.345      cycles                    #    3,389 GHz
     2.405.712.150      stalled-cycles-frontend   #   42,90% frontend cycles idle
     6.404.986.372      instructions              #    1,14  insn per cycle
                                                  #    0,38  stalled cycles per insn
     2.400.876.989      branches                  # 1450,835 M/sec
            65.008      branch-misses             #    0,00% of all branches

       1,655218510 seconds time elapsed

       1,655166000 seconds user
       0,000000000 seconds sys
```

## CRTP interface inline perf output

```bash
CRTP interface inline performance test.
 Performance counter stats for './crtp-performance ci':

        443,473932      task-clock (msec)         #    0,999 CPUs utilized
                 1      context-switches          #    0,002 K/sec
                 0      cpu-migrations            #    0,000 K/sec
               103      page-faults               #    0,232 K/sec
     1.484.542.038      cycles                    #    3,348 GHz
       682.277.169      stalled-cycles-frontend   #   45,96% frontend cycles idle
     3.203.712.119      instructions              #    2,16  insn per cycle
                                                  #    0,21  stalled cycles per insn
       800.682.208      branches                  # 1805,478 M/sec
            59.286      branch-misses             #    0,01% of all branches

       0,443799904 seconds time elapsed

       0,443794000 seconds user
       0,000000000 seconds sys
```