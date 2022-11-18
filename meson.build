project('gpt', 'cpp', default_options: ['warning_level=3', 'cpp_args=-std=c++2b'])

add_project_link_arguments(['-lstdc++fs'], language: 'cpp')

cpp = meson.get_compiler('cpp')

catch2 = dependency('catch2')

subdir('src')
subdir('test')
