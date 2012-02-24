clear
echo Compiling...
cd boot
nasm -f elf -o ../obj/loader.o loader.s

cd ../
i586-elf-gcc -o obj/kernel.o -c kernel.c

echo Linking...
cd obj
i586-elf-ld -T ../link.ld -o ../kernel.app loader.o kernel.o
echo Creating Media...
cd ../
cp kernel.app ./iso/System/CoreServices/Kernel/Kernel.app
grub-mkrescue -o bootable.iso iso
echo ----Booting-----------------------------------------
kvm -cdrom bootable.iso
