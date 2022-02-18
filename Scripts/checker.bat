@REM 2 Programme with test case generator for finding edge case


@echo off


for /l %%x in (1, 1, 1000) do (
    TestGenerator
    a > output.txt
    brute  > output2.txt
    fc output.txt output2.txt > checker_output.txt || exit /b
    echo %%x
)
echo all tests passed