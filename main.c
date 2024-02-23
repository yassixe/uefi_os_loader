#include <efi.h>
#include <efilib.h>


    // IN OUT UINTN                    *MemoryMapSize,
    // IN OUT EFI_MEMORY_DESCRIPTOR    *MemoryMap,
    // OUT UINTN                       *MapKey,
    // OUT UINTN                       *DescriptorSize,
    // OUT UINT32                      *DescriptorVersion

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  UINTN                       MemoryMapSize;
  EFI_MEMORY_DESCRIPTOR       MemoryMap;
  UINTN                       MapKey;
  UINTN                       DescriptorSize;
  UINT32                      DescriptorVersion;
  EFI_TIME current_time;
  EFI_TIME_CAPABILITIES capabilities;
  InitializeLib(ImageHandle, SystemTable);
  uefi_call_wrapper(ST->RuntimeServices->GetTime, 2, &current_time, &capabilities);
  Print(L"year:%d\nmounth:%d\nday:%d\nhour:%d\n",current_time.Year,current_time.Month,current_time.Day,current_time.Hour);
  //let's try to get memory mapping.
  //
  return EFI_SUCCESS;
}