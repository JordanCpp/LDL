
for %%f in (out\build\x86-Debug\test\Graphics\*.exe) do call %%f
for %%f in (out\build\x86-Debug\test\Events\*.exe) do call %%f

for %%f in (out\build\x64-Debug\test\Graphics\*.exe) do call %%f
for %%f in (out\build\x64-Debug\test\Events\*.exe) do call %%f

pause