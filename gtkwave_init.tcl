set signals [list \
    "top.cva6_top.clk_i" \
    "top.cva6_top.rst_ni" \
    "top.cva6_top.i_ariane.i_cva6.id_stage_i.decoder_i.pc_i" \
    "top.cva6_top.i_ariane.i_cva6.id_stage_i.decoder_i.pc_i_t0" \
    "top.cva6_top.mem_req_o" \
    "top.cva6_top.mem_req_o_t0" \
    "top.cva6_top.mem_addr_o" \
    "top.cva6_top.mem_addr_o_t0" \
    "top.cva6_top.mem_wdata_o" \
    "top.cva6_top.mem_wdata_o_t0" \
    "top.cva6_top.mem_rdata_i" \
    "top.cva6_top.mem_rdata_i_t0" \
    "top.cva6_top.i_ariane.i_cva6.ex_stage_i.lsu_i.i_load_unit.idx_q_t0" \
    "top.cva6_top.i_cache_subsystem.i_adapter.signal_0672" \
    "top.cva6_top.i_cache_subsystem.i_adapter.signal_1154" \
]

gtkwave::addSignalsFromList $signals
