const std = @import("std");

pub fn ft_putchar(c: u8) void {
    const buf: [1]u8 = [_]u8{c};
    _ = std.os.write(1, &buf) catch return;
}

pub fn ft_print_numbers() void {
    var num: u8 = '0';
    while (num <= '9')
    {
        ft_putchar(num);
        num += 1;
    }
}

pub fn main() !void {
    ft_print_numbers();
}

