@echo off
setlocal

cd /d %~dp0..
echo directory: %cd%

echo Engine pull
cd Engine
:: 最新化
git pull origin master

cd ..

echo Engine update Submodule！


:: Engine\bat\RunAll.bat を実行
echo Engine RunAll

call Engine\Bat\Run_ALL.bat

:: 開けてるか
if errorlevel 1 (
    echo Run_All.bat faild
) else (
    echo Run_All.bat sucess
)

echo RunAll.bat finished!

:: Engine\Externals をコピー
set SRC=Engine\Externals
set DEST=Externals

if not exist "%DEST%" (
    mkdir "%DEST%"
)

xcopy "%SRC%\*" "%DEST%\" /E /H /Y
echo Externals copied from %SRC% to %DEST%


pause