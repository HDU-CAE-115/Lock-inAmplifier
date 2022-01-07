
set MATLAB=D:\Software\Polyspace\R2020b

cd .

if "%1"=="" ("D:\Software\Polyspace\R2020b\bin\win64\gmake"  -f TpLockInAmp.mk all) else ("D:\Software\Polyspace\R2020b\bin\win64\gmake"  -f TpLockInAmp.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1