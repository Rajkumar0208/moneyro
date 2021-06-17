project('moneyro', 'cpp')

cmake = import('cmake')

fltk_subproj = cmake.subproject('fltk-1.3.6')
fltk_lib = fltk_subproj.dependency('fltk')
fltk_inc = fltk_subproj.include_directories('fltk')

moneyro_inc = include_directories('inc')
moneyro_src = include_directories('.')

gtest_subproj = subproject('gtest')
gtest_dep = gtest_subproj.get_variable('gtest_dep')

#TODO  mudar estrutura, colocar include e headers em diretórios src e include

sources = [
  'src/main.cpp',
  'src/lib/DateTime.cpp',
  'src/core/Profile.cpp',
  'src/core/Payment.cpp',
  'src/core/Account.cpp',
  'src/core/PaymentCollection.cpp',
  'src/components/MainWindow.cpp',
  'src/components/PaymentList.cpp'
  ]


executable('moneyro', sources, include_directories: [fltk_inc, moneyro_inc], dependencies: [fltk_lib])

tests = [
  {'name': 'payment_collection', 'sources': [], 'includes': []}
]

test_dir = 'src/tests/'
foreach t : tests
  test_source = test_dir + t['name'] + '.cpp'
  exe = executable(t['name'], [test_source], dependencies: [gtest_dep])
  test(t['name'], exe)
endforeach


