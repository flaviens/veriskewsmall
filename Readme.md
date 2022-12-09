# Rare clock skew in Verilator

## How to reproduce

Requirements: Verilator `Verilator 5.003 devel rev v4.228-192-g79682e607`.
Tried on Ubuntu 22.04.

```
bash build_test.sh # Verilate
bash make_test.sh  # Make
bash run_test.sh   # Run the simulation
bash wave.sh       # Display the relevant waves
```

## Expected and actual results

As described by the SystemVerilog source, the signal `signal_1154` should follow `signal_0672` with 1 cycle latency, if no negative reset is applied.

```
  always_ff @(posedge clk_i, negedge rst_ni)
    if (!rst_ni) signal_1154 <= 64'h0000000000000000;
    else signal_1154 <= signal_0672;
  assign icache_rtrn_o_t0[268:205] = signal_1154;
```

However, in some occurrence, both signal go from zero to `0xfffff000` at the exact same time, instead of `signal_1154` having 1 cycle delay.
