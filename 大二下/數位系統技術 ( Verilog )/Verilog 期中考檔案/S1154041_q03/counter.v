module counter(clk, rst, cnt);
    input clk, rst;
    output reg [31:0] cnt;
    parameter MX = 4;
    always @(posedge clk or posedge rst)
    begin
        if (rst)
        begin
            cnt = 0;
        end
        else 
        begin
            if(cnt == MX-1)
                cnt = 0;
            else
                cnt = cnt + 1;
        end
    end
endmodule