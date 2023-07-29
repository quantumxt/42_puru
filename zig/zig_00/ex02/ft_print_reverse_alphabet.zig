const std = @import("std");

pub fn ft_putchar(c: u8) void {
    const buf: [1]u8 = [_]u8{c};
    _ = std.os.write(1, &buf) catch return;
}

pub fn ft_print_reverse_alphabet() void {
    var buf: u8 = 'z';
    while (buf >= 'a')
    {
        ft_putchar(buf);
        buf -= 1;
    }
}

pub fn main() !void {
    ft_print_reverse_alphabet();
}

