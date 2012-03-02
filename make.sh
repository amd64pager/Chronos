CARGS="-Wall -Wextra -pipe -march=i586 -fno-omit-frame-pointer -O0 -nostdlib -fno-builtin -nostartfiles -nodefaultlibs -nostdinc -ffreestanding -I. -Iinclude"

clear
echo Compiling...
cd boot
nasm -f elf -o ../obj/loader.o loader.s
cd ../
#Screen
i586-elf-gcc $CARGS -o obj/lwtext.o -c screen/lwtext.c
i586-elf-gcc $CARGS -o obj/vsprintf.o -c screen/vsprintf.c
i586-elf-gcc $CARGS -o obj/printk.o -c screen/printk.c
#Hardware
nasm -f elf -o obj/asm_dstables.o hardware/descriptor_tables.s
i586-elf-gcc $CARGS -o obj/descriptor_tables.o -c hardware/descriptor_tables.c
i586-elf-gcc $CARGS -o obj/isr.o -c hardware/isr.c
i586-elf-gcc $CARGS -o obj/timer.o -c hardware/timer/timer.c
i586-elf-gcc $CARGS -o obj/kernel.o -c kernel.c
i586-elf-gcc $CARGS -o obj/global.o -c lib/global.c
echo Linking...
cd obj
i586-elf-ld -T ../link.ld -o ../kernel.app loader.o kernel.o global.o lwtext.o vsprintf.o printk.o asm_dstables.o descriptor_tables.o isr.o timer.o


echo Creating Media...
cd ../
cp kernel.app ./iso/System/Library/CoreServices/Kernel/Kernel.app
grub-mkrescue -o bootable.iso iso
echo -------Booting-----------------------------------------
kvm -cdrom bootable.iso
