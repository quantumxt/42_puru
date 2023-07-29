const std = @import("std");

pub fn ft_putchar(c: u8) void {
    var buf: [1]u8 = [_]u8{c};
    _ = std.os.write(1, &buf) catch return;
}

pub fn main() !void {
    ft_putchar('a');
    ft_putchar('b');
}

