# OlcChip8
一个简单的chip 8模拟器用c++和olcPixelGameEngine引擎编写（命令行模式），前端图形界面用C#编写。
## 用法
### 命令行模式：
OlcChip8 [-s Pixel_Scale] [-b Background_Pixel_Color] [-f Foreground_Pixel_Color] [-c Cpu_hz] [-h] rom_path

选项:

          -s Pixel_Scale      像素放大的倍数，默认值是10。
          -b Background_Pixel_Color     背景像素的颜色（RRRGGGBBB），默认值是000000000。
          -f Foreground_Pixel_Color     前景像素的颜色（RRRGGGBBB），默认值是255255255。
          -c Cpu_hz     Chip8 CPU的频率，默认是500赫兹，范围是（1hz-1000hz）。
          -h      显示帮忙。
          rom_path      加载rom的路径。
          
实例：

      OlcChip8 -f 064128128 -b 000000000 -c 600 d:\INVDERS
      
      [![OlcChip8 Emulator Command Line](https://github.com/NeroJin/OlcChip8/raw/master/doc/pic/cmd_sample.png)](https://github.com/NeroJin/OlcChip8/blob/master/doc/pic/cmd_sample.png)
