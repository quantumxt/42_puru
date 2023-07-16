import sys
import random as rd
from datetime import datetime

SHOW_GEN = True
# Get time
now = datetime.now()
tstamp = now.strftime("%d%m%Y_%H%M%S")
header = """
░█▄▒▄█▒▄▀▄▒█▀▄░▄▀▒▒██▀░█▄░█
░█▒▀▒█░█▀█░█▀▒░▀▄█░█▄▄░█▒▀█
"""
print(header)
if len(sys.argv) != 4:
	sys.exit("Please enter with the following format:\n map_gen [x] [y] [density]")
x, y, density = map(int, sys.argv[1:])
print(f'Generating map...\nx: {x}\ty: {y}\tDensity: {density}\n')

region_empty = '.'
region_obstacle = 'o'
region_solution = 'x'
region_mapping = f'{region_empty}{region_obstacle}{region_solution}'
print(f'{region_empty}: Empty\n{region_obstacle}: Obstacle\n{region_solution}: Valid region\n==============================')

lines = []
filename = f'map_{tstamp}_{y}'
lines.append(f'{y}{region_mapping}\n')
if SHOW_GEN:
	print(f'{y}{region_mapping}')
for i in range(y):
	l = ""
	for j in range(x):
		if int(rd.randint(0, y-1) * 2) < density:
			l += region_obstacle
		else:
			l += region_empty
	l += '\n'
	if SHOW_GEN:
		print(l, end = '')
	lines.append(l)
# Save file
print(f'==============================\nSaving map as [ {filename} ]')
with open(filename, 'x') as f:
	f.writelines(''.join(lines))
print('Done!')
