可能缺失的 *.dll

放入 C:\Windows\System32 中

然后 Win+R 运行 `regsvr32 %windir%\system32\name.dll /s` 即可，注意将 name.dll 换成实际缺失添加的文件
