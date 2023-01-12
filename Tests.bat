
for %%f in (out\build\%1\test\Graphics\*.exe) do call %%f
for %%f in (out\build\%1\test\Events\*.exe) do call %%f
for %%f in (out\build\%1\test\Allocators\*.exe) do call %%f
for %%f in (out\build\%1\test\Loaders\*.exe) do call %%f
for %%f in (out\build\%1\test\Core\*.exe) do call %%f
for %%f in (out\build\%1\test\Input\*.exe) do call %%f
for %%f in (out\build\%1\test\Containers\*.exe) do call %%f
for %%f in (out\build\%1\test\Creators\*.exe) do call %%f
for %%f in (out\build\%1\test\Graphics\Render\*.exe) do call %%f