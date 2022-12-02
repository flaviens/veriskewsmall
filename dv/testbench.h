// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "Vwt_axi_adapter.h"
#include "verilated.h"

#if VM_TRACE
#if VM_TRACE_FST
#include <verilated_fst_c.h>
#else
#include <verilated_vcd_c.h>
#endif // VM_TRACE_FST
#endif // VM_TRACE

#include <iostream>
#include <fstream>
#include <stdlib.h>

#ifndef TESTBENCH_H
#define TESTBENCH_H

#if VM_TRACE
// Depth of the trace.
const int kTraceLevel = 6;
#endif // VM_TRACE

typedef Vwt_axi_adapter Module;

typedef struct {
// Adapter
  uint32_t clk_i;                // 1 bit
  uint32_t rst_ni;               // 1 bit
  uint32_t icache_data_req_i;    // 1 bit
  uint32_t dcache_data_req_i;    // 1 bit
  uint64_t icache_data_i;        // 61 bits
  uint32_t dcache_data_i[5];     // 135 bits
  uint32_t axi_resp_i[3];        // 86 bits
  uint32_t icache_data_req_i_t0; // 1 bit
  uint32_t dcache_data_req_i_t0; // 1 bit
  uint64_t icache_data_i_t0;     // 61 bits
  uint32_t dcache_data_i_t0[5];  // 135 bits
  uint32_t axi_resp_i_t0[3];     // 86 bits

// AXI shim outputs
  uint32_t axi_req_o_t0[9];
  uint32_t axi_req_o[9];
  uint64_t axi_rd_data_t0;
  uint64_t axi_rd_data;
  uint64_t axi_rd_exokay_t0;
  uint64_t axi_rd_exokay;
  uint64_t axi_rd_gnt_t0;
  uint64_t axi_rd_gnt;
  uint64_t axi_rd_id_out_t0;
  uint64_t axi_rd_id_out;
  uint64_t axi_rd_last_t0;
  uint64_t axi_rd_last;
  uint64_t axi_rd_user_t0;
  uint64_t axi_rd_user;
  uint64_t axi_rd_valid_t0;
  uint64_t axi_rd_valid;
  uint64_t axi_wr_exokay_t0;
  uint64_t axi_wr_exokay;
  uint64_t axi_wr_gnt_t0;
  uint64_t axi_wr_gnt;
  uint64_t axi_wr_id_out_t0;
  uint64_t axi_wr_id_out;
  uint64_t axi_wr_valid_t0;
  uint64_t axi_wr_valid;
} single_input_recording_t;

// This class implements elementary interaction with the design under test.
class Testbench {
 public:
  Testbench(const std::string &trace_filename = "")
      : module_(new Module), tick_count_(0l) {

#if VM_TRACE
#if VM_TRACE_FST
    trace_ = new VerilatedFstC;
#else // VM_TRACE_FST
    trace_ = new VerilatedVcdC;
#endif // VM_TRACE_FST
    module_->trace(trace_, kTraceLevel);
    trace_->open(trace_filename.c_str());
#endif // VM_TRACE
  }

  ~Testbench(void) { close_trace(); }

  void close_trace(void) {
#if VM_TRACE  
    trace_->close();
#endif // VM_TRACE
  }

  std::unique_ptr<Module> module_;
  #if VM_TRACE
  #if VM_TRACE_FST
    VerilatedFstC *trace_;
  #else // VM_TRACE_FST
    VerilatedVcdC *trace_;
  #endif // VM_TRACE_FST
  #endif // VM_TRACE
 private:
  vluint32_t tick_count_;


  // Masks that contain ones in the corresponding fields.
  uint32_t id_mask_;
  uint32_t content_mask_;
};

#endif // TESTBENCH_H
