project('moneyro', 'cpp')

cmake = import('cmake')

fltk_subproj = cmake.subproject('fltk-1.3.6')
fltk_dep = fltk_subproj.dependency('fltk')

moneyro_inc = include_directories('inc')
moneyro_src = include_directories('.')

sqlite3_subproj = subproject('sqlite3')
sqlite3_dep = sqlite3_subproj.get_variable('sqlite3_dep')

gtest_subproj = subproject('gtest')
gtest_dep = gtest_subproj.get_variable('gtest_dep')

#TODO  mudar estrutura, colocar include e headers em diretórios src e include

sources = [
  'src/main.cpp',
  'src/lib/DateTime.cpp',
  'src/lib/sFLTK.cpp',
  'src/core/Profile.cpp',
  'src/core/Payment.cpp',
  'src/core/Account.cpp',
  'src/core/PaymentCollection.cpp',
  'src/components/MainWindow.cpp',
  'src/components/PaymentList.cpp',
  #'src/database/Model.cpp',
  'src/database/Database.cpp'
  ]

executable('moneyro', sources, include_directories: [moneyro_inc], dependencies: [fltk_dep, sqlite3_dep], cpp_args:'-lpthread -g')

# Tests

test_dir = 'src/tests/'
tests = [
  {'name': 'payment_collection', 'sources': ['src/core/PaymentCollection.cpp', 'src/core/Payment.cpp', 'src/lib/DateTime.cpp', 'src/core/Account.cpp'], 'includes': [], 'flags': []},
  {'name': 'datetime', 'sources': ['src/lib/DateTime.cpp'], 'includes': [], 'flags': []}

]

foreach t : tests
  #TODO remove path separator from executable name
  test_source = test_dir + t['name'] + '.cpp'
  exe = executable('tests/' + t['name'], [test_source] + t['sources'], dependencies: [gtest_dep], include_directories: [moneyro_inc], cpp_args: t['flags'])
  test(t['name'], exe)
endforeach
