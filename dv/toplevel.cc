// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "testbench.h"
#include "ticks.h"

// Read the recorded trace
std::vector<single_input_recording_t> read_recorded_trace(std::string path_to_recording) {
  std::vector<single_input_recording_t> recorded_trace;
  size_t num_steps = -1;

  std::ifstream dumpfile;
  dumpfile.open(path_to_recording.c_str());
  dumpfile >> num_steps;
  for (size_t step_id = 0; step_id < num_steps; step_id++) {
    single_input_recording_t acquired;
    // Mem top
    dumpfile >> acquired.boot_addr_i;
    dumpfile >> acquired.boot_addr_i_t0;
    dumpfile >> acquired.clk_i;
    dumpfile >> acquired.debug_req_i;
    dumpfile >> acquired.debug_req_i_t0;
    dumpfile >> acquired.hart_id_i;
    dumpfile >> acquired.hart_id_i_t0;
    dumpfile >> acquired.ipi_i;
    dumpfile >> acquired.ipi_i_t0;
    dumpfile >> acquired.irq_i;
    dumpfile >> acquired.irq_i_t0;
    dumpfile >> acquired.mem_gnt_i;
    dumpfile >> acquired.mem_gnt_i_t0;
    dumpfile >> acquired.mem_rdata_i;
    dumpfile >> acquired.mem_rdata_i_t0;
    dumpfile >> acquired.rst_ni;
    dumpfile >> acquired.time_irq_i;
    dumpfile >> acquired.time_irq_i_t0;

    recorded_trace.push_back(acquired);
  }
  dumpfile.close();
  return recorded_trace;
}

static void feed_tb(Testbench *tb, single_input_recording_t acquired) {
  // Mem top
  tb->module_->boot_addr_i    = acquired.boot_addr_i;
  tb->module_->boot_addr_i_t0 = acquired.boot_addr_i_t0;
  tb->module_->debug_req_i    = acquired.debug_req_i;
  tb->module_->debug_req_i_t0 = acquired.debug_req_i_t0;
  tb->module_->hart_id_i      = acquired.hart_id_i;
  tb->module_->hart_id_i_t0   = acquired.hart_id_i_t0;
  tb->module_->ipi_i          = acquired.ipi_i;
  tb->module_->ipi_i_t0       = acquired.ipi_i_t0;
  tb->module_->irq_i          = acquired.irq_i;
  tb->module_->irq_i_t0       = acquired.irq_i_t0;
  tb->module_->mem_gnt_i      = acquired.mem_gnt_i;
  tb->module_->mem_gnt_i_t0   = acquired.mem_gnt_i_t0;
  tb->module_->mem_rdata_i    = acquired.mem_rdata_i;
  tb->module_->mem_rdata_i_t0 = acquired.mem_rdata_i_t0;
  tb->module_->rst_ni         = acquired.rst_ni;
  tb->module_->time_irq_i     = acquired.time_irq_i;
  tb->module_->time_irq_i_t0  = acquired.time_irq_i_t0;
}

/**
 * Runs the recorded trace.
 *
 * @param tb a pointer to a testbench instance
 * @param simlen the number of cycles to run
 */
static void run_test(Testbench *tb, std::string path_to_recording) {
  std::vector<single_input_recording_t> recorded_trace = read_recorded_trace(path_to_recording);
  uint32_t clk = 0;
  for (size_t step_id = 0; step_id < recorded_trace.size(); step_id++) {
    single_input_recording_t acquired = recorded_trace[step_id];
    printf("Step %d\n", step_id);
    feed_tb(tb, acquired);
    tb->module_->clk_i = 0;
    tb->module_->eval();
#if VM_TRACE
    tb->trace_->dump(5*step_id/3+4);
#endif // VM_TRACE
    tb->module_->clk_i = 1;
    tb->module_->eval();
#if VM_TRACE
    tb->trace_->dump(5*step_id/3+5);
#endif // VM_TRACE
    tb->module_->clk_i = 0;
    tb->module_->eval();
#if VM_TRACE
    tb->trace_->dump(5*step_id/3+7);
    tb->trace_->flush();
#endif // VM_TRACE
  }
}

int main(int argc, char **argv, char **env) {

  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(VM_TRACE);

  Testbench *tb = new Testbench(cl_get_tracefile());

  ////////
  // Run the recorded trace.
  ////////

  run_test(tb, cl_get_recordingfile());

  ////////
  // Display the results.
  ////////
  std::cout << "Testbench complete!" << std::endl;
  
  delete tb;
  exit(0);
}
