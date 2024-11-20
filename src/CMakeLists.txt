# This is the main binary. List your C files here.
add_executable(sleep_blink
    sleep_blink.c
    )
add_executable(thread_blink
    thread_blink.c
    )
add_executable(busy_blink
    busy_blink.c
    )
add_executable(interrupt_toggle
    interrupt_toggle.c
    )

pico_set_program_name(sleep_blink "test")
pico_set_program_version(sleep_blink "0.1")

pico_set_program_name(thread_blink "test")
pico_set_program_version(thread_blink "0.1")

pico_set_program_name(busy_blink "test")
pico_set_program_version(busy_blink "0.1")

pico_set_program_name(interrupt_toggle "test")
pico_set_program_version(interrupt_toggle "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(sleep_blink 0)
pico_enable_stdio_usb(sleep_blink 1)
pico_enable_stdio_uart(thread_blink 0)
pico_enable_stdio_usb(thread_blink 1)
pico_enable_stdio_uart(busy_blink 0)
pico_enable_stdio_usb(busy_blink 1)
pico_enable_stdio_uart(interrupt_toggle 0)
pico_enable_stdio_usb(interrupt_toggle 1)

# Add the libraries to the build
target_link_libraries(sleep_blink PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
target_link_libraries(thread_blink PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
target_link_libraries(busy_blink PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
target_link_libraries(interrupt_toggle PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(sleep_blink PRIVATE
        pico_cyw43_arch_none
    )
    target_link_libraries(thread_blink PRIVATE
        pico_cyw43_arch_none
    )
    target_link_libraries(busy_blink PRIVATE
        pico_cyw43_arch_none
    )
    target_link_libraries(interrupt_toggle PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(sleep_blink)
pico_add_extra_outputs(thread_blink)
pico_add_extra_outputs(busy_blink)
pico_add_extra_outputs(interrupt_toggle)

add_custom_target(flash_sleep picotool load -f $<TARGET_FILE:sleep_blink> DEPENDS sleep_blink)
add_custom_target(flash_thread picotool load -f $<TARGET_FILE:thread_blink> DEPENDS thread_blink)
add_custom_target(flash_busy picotool load -f $<TARGET_FILE:busy_blink> DEPENDS busy_blink)
add_custom_target(flash_interrupt picotool load -f $<TARGET_FILE:interrupt_toggle> DEPENDS interrupt_toggle)
