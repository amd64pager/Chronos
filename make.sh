clear
echo Compiling...
cd boot
nasm -f elf -o ../obj/loader.o loader.s

cd ../screen
i586-elf-gcc -o ../obj/lwtext.o -c lwtext.c
i586-elf-gcc -o ../obj/vsprintf.o -c vsprintf.c
i586-elf-gcc -o ../obj/printk.o -c printk.c
cd ../
i586-elf-gcc -o obj/kernel.o -c kernel.c
i586-elf-gcc -o obj/global.o -c lib/global.c
echo Linking...
cd obj
i586-elf-ld -T ../link.ld -o ../kernel.app loader.o kernel.o global.o lwtext.o vsprintf.o printk.o

echo Creating Media...
cd ../
cp kernel.app ./iso/System/Library/CoreServices/Kernel/Kernel.app
grub-mkrescue -o bootable.iso iso
echo ----Booting-----------------------------------------
kvm -cdrom bootable.iso
