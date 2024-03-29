dd if=/dev/zero of=build/uefi.img bs=512 count=93750
parted build/uefi.img -s -a minimal mklabel gpt
parted build/uefi.img -s -a minimal mkpart EFI FAT16 2048s 93716s
parted build/uefi.img -s -a minimal toggle 1 boot
dd if=/dev/zero of=/tmp/part.img bs=512 count=91669
mformat -i /tmp/part.img -h 32 -t 32 -n 64 -c 1
mcopy -i /tmp/part.img ./build/main.efi ::
dd if=/tmp/part.img of=build/uefi.img bs=512 count=91669 seek=2048 conv=notrunc