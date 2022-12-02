set signals [list \
    "top.wt_axi_adapter.clk_i" \
    "top.wt_axi_adapter.rst_ni" \
    "top.wt_axi_adapter.signal_0672" \
    "top.wt_axi_adapter.signal_1154" \
]

gtkwave::addSignalsFromList $signals
