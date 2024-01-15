@echo off

set pth=..\examples\

call vc6 01Window %pth%
call vc6 02Render %pth%
call vc6 03Fps    %pth%
call vc6 04Clear  %pth%

pause