#include <efi.h>
#include <efilib.h>






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
  // unsigned long val;
  // asm volatile("mov %%cr0, %0" : "=r" (val));
  // Print(L"cr0: 0x%x\n",val);
  uefi_call_wrapper(ST->ConOut->Reset,1,ST->ConOut);
  uefi_call_wrapper(ST->ConOut->ClearScreen,1,ST->ConOut);
  UINTN mode_id = (UINTN)(ST->ConOut->Mode->Mode);
  UINTN col,lig;
  uefi_call_wrapper(ST->ConOut->QueryMode,4,ST->ConOut,mode_id,&col,&lig);
  Print(L"mode:%d = %d*%d\n",ST->ConOut->Mode->Mode,lig,col);
  return EFI_SUCCESS;
}