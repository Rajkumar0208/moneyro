project('moneyro', 'cpp')

# 1) Dependencies
cmake = import('cmake')

fltk_subproj = cmake.subproject('fltk-1.3.6')
fltk_dep = fltk_subproj.dependency('fltk')

moneyro_inc = include_directories('inc')
moneyro_src = include_directories('.')

jsoncpp_subproj = subproject('jsoncpp')
jsoncpp_dep = jsoncpp_subproj.get_variable('jsoncpp_dep')
gtest_subproj = subproject('gtest')
gtest_dep = gtest_subproj.get_variable('gtest_dep')


# 2) Source files
sources = files(
  'src/main.cpp',
  'src/lib/DateTime.cpp',
  'src/lib/sFLTK.cpp',
  'src/core/Profile.cpp',
  'src/core/Payment.cpp',
  'src/core/Account.cpp',
  'src/core/PaymentCollection.cpp',
  'src/components/MainWindow.cpp',
  'src/components/PaymentList.cpp'
  )

# 3) Lint (Not Working)
clang_tidy = find_program('clang-tidy')

#TODO see if this is working
if clang_tidy.found()
  run_target(
    'tidy',
    command: [
      clang_tidy,
      '--checks=cppcoreguidelines-*',
      'p', meson.build_root()
      ] + sources
    )
endif


# 4) Tests
test_dir = 'src/tests/'
tests = [
  {'name': 'payment_collection', 'sources': ['src/core/PaymentCollection.cpp', 'src/core/Payment.cpp', 'src/lib/DateTime.cpp', 'src/core/Account.cpp'], 'includes': [], 'flags': []},
  {'name': 'datetime', 'sources': ['src/lib/DateTime.cpp'], 'includes': [], 'flags': []}
]

foreach t : tests
  #TODO remove path separator from executable name
  test_source = test_dir + t['name'] + '.cpp'
  exe = executable('tests/' + t['name'], [test_source] + t['sources'], dependencies: [gtest_dep,jsoncpp_dep], include_directories: [moneyro_inc], cpp_args: t['flags'])
  test(t['name'], exe)
endforeach

# 5) Executable
executable('moneyro', sources, include_directories: [moneyro_inc], dependencies: [fltk_dep, jsoncpp_dep], cpp_args:['-g', '-Wall'])
