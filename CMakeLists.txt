#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2020-12-25 16:38:01.001483
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-pedantic"
      "-DINSIDE_DANTE"
      "-fmax-errors=5"
      "-D_ANSI_OUTPUT"
      "-ggdb3"
      "-xc"
      "-Wno-error=unused-parameter"
      "-Werror=vla"
      "-Wno-parentheses"
      "-Wextra"
      "-std=c11"
      "-Wall"
      "-D_GNU_SOURCE"
      "-fdiagnostics-color"
      "-Wno-error=parentheses"
      "-Wno-error=implicit-fallthrough"
      "-Werror"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-Map=main.map"
        "-ggdb3"
        "-Wl,-wrap,main"
        "-Wl,-cref"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "file_reader.c"
        "main.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)