# Performance outputs
## Pimpl class perf output

```bash
Pimpl class performance test.
 Performance counter stats for './pimpl-performance p':

      44794,125369      task-clock (msec)         #    1,000 CPUs utilized
                45      context-switches          #    0,001 K/sec
                 1      cpu-migrations            #    0,000 K/sec
             2.052      page-faults               #    0,046 K/sec
   152.373.249.923      cycles                    #    3,402 GHz
    92.825.410.822      stalled-cycles-frontend   #   60,92% frontend cycles idle
   160.140.649.576      instructions              #    1,05  insn per cycle
                                                  #    0,58  stalled cycles per insn
    50.026.175.393      branches                  # 1116,802 M/sec
           906.526      branch-misses             #    0,00% of all branches

      44,795194478 seconds time elapsed

      44,766529000 seconds user
       0,027999000 seconds sys
```

## Abstract class perf output

```bash
Abstract class performance test.
 Performance counter stats for './pimpl-performance a':

      37325,619400      task-clock (msec)         #    1,000 CPUs utilized
                13      context-switches          #    0,000 K/sec
                 0      cpu-migrations            #    0,000 K/sec
             1.664      page-faults               #    0,045 K/sec
   126.963.916.851      cycles                    #    3,402 GHz
    58.873.071.224      stalled-cycles-frontend   #   46,37% frontend cycles idle
   160.087.484.676      instructions              #    1,26  insn per cycle
                                                  #    0,37  stalled cycles per insn
    50.015.567.704      branches                  # 1339,980 M/sec
           539.220      branch-misses             #    0,00% of all branches

      37,326189234 seconds time elapsed

      37,321961000 seconds user
       0,004000000 seconds sys
```

## Inline class peft output:

```bash
Inline class performance test.
 Performance counter stats for './pimpl-performance i':

      27474,790000      task-clock (msec)         #    0,997 CPUs utilized
             1.816      context-switches          #    0,066 K/sec
                 1      cpu-migrations            #    0,000 K/sec
             1.663      page-faults               #    0,061 K/sec
    93.434.059.202      cycles                    #    3,401 GHz
    73.368.138.415      stalled-cycles-frontend   #   78,52% frontend cycles idle
    80.131.997.535      instructions              #    0,86  insn per cycle
                                                  #    0,92  stalled cycles per insn
    10.027.431.994      branches                  #  364,968 M/sec
           638.308      branch-misses             #    0,01% of all branches

      27,559031383 seconds time elapsed

      27,410388000 seconds user
       0,067946000 seconds sys
```