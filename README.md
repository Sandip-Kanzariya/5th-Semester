[🔙 Go Back](https://github.com/Sandip-Kanzariya/5th-Semester)

# MFP 
### DOS Box Setup & Run : 

>Choose Any Drive and create 📁(dosprogs) folder

>Install downloaded DOSBox & put DEBUG125 in 📁(dosprogs) folder

![image](https://github.com/Sandip-Kanzariya/Advanced-Algorithms/assets/105594748/f2c8749d-5401-4885-bd78-7a9df632a987)

> Choose Drive where you created 📁(dosprogs) folder created.
``` 
mount D D:\dosprogs
```

```
D:
```

```
cd DEBUG125
```

```
debug
```

> TASM : asm file assembler

![image](https://github.com/Sandip-Kanzariya/5th-Semester/assets/105594748/fd5969be-fff2-4581-8848-943f69a1aed1)

```
cd tasm
```
>show content of file : 
```
type file.extention
```

>Assembly to Binary (Machine) Code (file.asm -> file.obj): 
```
tasm file.asm
```

>Binary (Machine) Code to file.exe & file.map(file.asm -> file.obj): 
```
tlink file.obj
```


