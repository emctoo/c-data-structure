env = Environment(tools = ['mingw'])
env.MergeFlags([
	'-g',
	'-std=c99',
	])
source_files = [
	'sort.c',
	]
env.Program(target = 'tros', source = ['sort.c'])