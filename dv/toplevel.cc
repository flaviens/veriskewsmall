// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "Vwt_axi_adapter__Syms.h"
#include "Vwt_axi_adapter___024root.h"

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
    // Adapter
    dumpfile >> acquired.clk_i;
    dumpfile >> acquired.rst_ni;
    dumpfile >> acquired.icache_data_req_i;
    dumpfile >> acquired.dcache_data_req_i;
    dumpfile >> acquired.icache_data_i;
    dumpfile >> acquired.dcache_data_i[0];
    dumpfile >> acquired.dcache_data_i[1];
    dumpfile >> acquired.dcache_data_i[2];
    dumpfile >> acquired.dcache_data_i[3];
    dumpfile >> acquired.dcache_data_i[4];
    dumpfile >> acquired.axi_resp_i[0];
    dumpfile >> acquired.axi_resp_i[1];
    dumpfile >> acquired.axi_resp_i[2];
    dumpfile >> acquired.icache_data_req_i_t0;
    dumpfile >> acquired.dcache_data_req_i_t0;
    dumpfile >> acquired.icache_data_i_t0;
    dumpfile >> acquired.dcache_data_i_t0[0];
    dumpfile >> acquired.dcache_data_i_t0[1];
    dumpfile >> acquired.dcache_data_i_t0[2];
    dumpfile >> acquired.dcache_data_i_t0[3];
    dumpfile >> acquired.dcache_data_i_t0[4];
    dumpfile >> acquired.axi_resp_i_t0[0];
    dumpfile >> acquired.axi_resp_i_t0[1];
    dumpfile >> acquired.axi_resp_i_t0[2];

    dumpfile >> acquired.axi_req_o_t0[0];
    dumpfile >> acquired.axi_req_o_t0[1];
    dumpfile >> acquired.axi_req_o_t0[2];
    dumpfile >> acquired.axi_req_o_t0[3];
    dumpfile >> acquired.axi_req_o_t0[4];
    dumpfile >> acquired.axi_req_o_t0[5];
    dumpfile >> acquired.axi_req_o_t0[6];
    dumpfile >> acquired.axi_req_o_t0[7];
    dumpfile >> acquired.axi_req_o_t0[8];
    dumpfile >> acquired.axi_req_o[0];
    dumpfile >> acquired.axi_req_o[1];
    dumpfile >> acquired.axi_req_o[2];
    dumpfile >> acquired.axi_req_o[3];
    dumpfile >> acquired.axi_req_o[4];
    dumpfile >> acquired.axi_req_o[5];
    dumpfile >> acquired.axi_req_o[6];
    dumpfile >> acquired.axi_req_o[7];
    dumpfile >> acquired.axi_req_o[8];
    dumpfile >> acquired.axi_rd_data_t0;
    dumpfile >> acquired.axi_rd_data;
    dumpfile >> acquired.axi_rd_exokay_t0;
    dumpfile >> acquired.axi_rd_exokay;
    dumpfile >> acquired.axi_rd_gnt_t0;
    dumpfile >> acquired.axi_rd_gnt;
    dumpfile >> acquired.axi_rd_id_out_t0;
    dumpfile >> acquired.axi_rd_id_out;
    dumpfile >> acquired.axi_rd_last_t0;
    dumpfile >> acquired.axi_rd_last;
    dumpfile >> acquired.axi_rd_user_t0;
    dumpfile >> acquired.axi_rd_user;
    dumpfile >> acquired.axi_rd_valid_t0;
    dumpfile >> acquired.axi_rd_valid;
    dumpfile >> acquired.axi_wr_exokay_t0;
    dumpfile >> acquired.axi_wr_exokay;
    dumpfile >> acquired.axi_wr_gnt_t0;
    dumpfile >> acquired.axi_wr_gnt;
    dumpfile >> acquired.axi_wr_id_out_t0;
    dumpfile >> acquired.axi_wr_id_out;
    dumpfile >> acquired.axi_wr_valid_t0;
    dumpfile >> acquired.axi_wr_valid;

    recorded_trace.push_back(acquired);
  }
  dumpfile.close();
  return recorded_trace;
}

static void feed_tb(Testbench *tb, single_input_recording_t acquired) {
  // Adapter
  tb->module_->clk_i                = acquired.clk_i;
  tb->module_->rst_ni               = acquired.rst_ni;
  tb->module_->icache_data_req_i    = acquired.icache_data_req_i;
  tb->module_->dcache_data_req_i    = acquired.dcache_data_req_i;
  tb->module_->icache_data_i        = acquired.icache_data_i;
  tb->module_->dcache_data_i[0]     = acquired.dcache_data_i[0];
  tb->module_->dcache_data_i[1]     = acquired.dcache_data_i[1];
  tb->module_->dcache_data_i[2]     = acquired.dcache_data_i[2];
  tb->module_->dcache_data_i[3]     = acquired.dcache_data_i[3];
  tb->module_->dcache_data_i[4]     = acquired.dcache_data_i[4];
  tb->module_->axi_resp_i[0]        = acquired.axi_resp_i[0];
  tb->module_->axi_resp_i[1]        = acquired.axi_resp_i[1];
  tb->module_->axi_resp_i[2]        = acquired.axi_resp_i[2];
  tb->module_->icache_data_req_i_t0 = acquired.icache_data_req_i_t0;
  tb->module_->dcache_data_req_i_t0 = acquired.dcache_data_req_i_t0;
  tb->module_->icache_data_i_t0     = acquired.icache_data_i_t0;
  tb->module_->dcache_data_i_t0[0]  = acquired.dcache_data_i_t0[0];
  tb->module_->dcache_data_i_t0[1]  = acquired.dcache_data_i_t0[1];
  tb->module_->dcache_data_i_t0[2]  = acquired.dcache_data_i_t0[2];
  tb->module_->dcache_data_i_t0[3]  = acquired.dcache_data_i_t0[3];
  tb->module_->dcache_data_i_t0[4]  = acquired.dcache_data_i_t0[4];
  tb->module_->axi_resp_i_t0[0]     = acquired.axi_resp_i_t0[0];
  tb->module_->axi_resp_i_t0[1]     = acquired.axi_resp_i_t0[1];
  tb->module_->axi_resp_i_t0[2]     = acquired.axi_resp_i_t0[2];

  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[0]   = acquired.axi_req_o_t0[0];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[1]   = acquired.axi_req_o_t0[1];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[2]   = acquired.axi_req_o_t0[2];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[3]   = acquired.axi_req_o_t0[3];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[4]   = acquired.axi_req_o_t0[4];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[5]   = acquired.axi_req_o_t0[5];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[6]   = acquired.axi_req_o_t0[6];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[7]   = acquired.axi_req_o_t0[7];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o_t0[8]   = acquired.axi_req_o_t0[8];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[0]      = acquired.axi_req_o[0];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[1]      = acquired.axi_req_o[1];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[2]      = acquired.axi_req_o[2];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[3]      = acquired.axi_req_o[3];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[4]      = acquired.axi_req_o[4];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[5]      = acquired.axi_req_o[5];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[6]      = acquired.axi_req_o[6];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[7]      = acquired.axi_req_o[7];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_req_o[8]      = acquired.axi_req_o[8];
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_data_t0    = acquired.axi_rd_data_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_data       = acquired.axi_rd_data;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_exokay_t0  = acquired.axi_rd_exokay_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_exokay     = acquired.axi_rd_exokay;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_gnt_t0     = acquired.axi_rd_gnt_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_gnt        = acquired.axi_rd_gnt;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_id_out_t0  = acquired.axi_rd_id_out_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_id_out     = acquired.axi_rd_id_out;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_last_t0    = acquired.axi_rd_last_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_last       = acquired.axi_rd_last;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_user_t0    = acquired.axi_rd_user_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_user       = acquired.axi_rd_user;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_valid_t0   = acquired.axi_rd_valid_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_rd_valid      = acquired.axi_rd_valid;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_exokay_t0  = acquired.axi_wr_exokay_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_exokay     = acquired.axi_wr_exokay;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_gnt_t0     = acquired.axi_wr_gnt_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_gnt        = acquired.axi_wr_gnt;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_id_out_t0  = acquired.axi_wr_id_out_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_id_out     = acquired.axi_wr_id_out;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_valid_t0   = acquired.axi_wr_valid_t0;
  tb->module_->rootp->vlSymsp->TOP__wt_axi_adapter.axi_wr_valid      = acquired.axi_wr_valid;
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
  for (size_t step_id = 0; step_id < recorded_trace.size(); step_id+=3) {
    single_input_recording_t acquired;
    printf("Step %d\n", step_id);
    acquired = recorded_trace[step_id];
    feed_tb(tb, acquired);
    tb->module_->eval();
#if VM_TRACE
    tb->trace_->dump(5*step_id/3+4);
#endif // VM_TRACE

    acquired = recorded_trace[step_id+1];
    feed_tb(tb, acquired);
    tb->module_->eval();
#if VM_TRACE
    tb->trace_->dump(5*step_id/3+5);
#endif // VM_TRACE

    acquired = recorded_trace[step_id+2];
    feed_tb(tb, acquired);
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
