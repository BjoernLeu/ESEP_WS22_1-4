/**
 * Header-Datei für GPIO-Schnittstellen
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#ifndef SRC_UTILS_GPIO_H_
#define SRC_UTILS_GPIO_H_

//ADC Bank
#define ADC_BANK mmap_device_io(0x2000, (uint64_t) 0x44E0D000)

//GPIO Bank
#define GPIO_BANK_0 mmap_device_io(0x1000, (uint64_t) 0x44E07000)
#define GPIO_BANK_1 mmap_device_io(0x1000, (uint64_t) 0x4804C000)
#define GPIO_BANK_2 mmap_device_io(0x1000, (uint64_t) 0x481AC000)

//GPIO 0, folgende Bits sind Eingänge
#define IN_INLET 1<<2                   //low w.t.
#define IN_SWITCH 1<<5                  //low w.t.
#define IS_METAL 1<<7                   //high w.t.
#define ACTIVE_SWITCH 1<<14             //high w.t.
#define LIMIT_SLIDE 1<<15               //low w.t.
#define IN_OUTLET 1<<20                   //low w.t.
#define START 1<<22                     //high wenn gedrückt
#define STOP 1<<23                      //low wenn gedrückt
#define RESET 1<<26                     //high wenn gedrückt
#define ESTOP 1<<27                     //low wenn gedrückt

//GPIO 1, folgende Bits sind Ausgänge
#define MOTOR_RIGHT 1<<12
#define MOTOR_SLOW 1<<14
#define MOTOR_STOP 1<<15
#define LIGHT_RED 1<<16
#define LIGHT_YELLOW 1<<17
#define LIGHT_GREEN 1<<18
#define OPEN_SWITCH 1<<19

//GPIO 2, folgende Bits sind Ausgänge
#define LED_START 1<<2
#define LED_RESET 1<<3
#define SIGNAL_FIRST 1<<4
#define SIGNAL_SECOND 1<<5

//Flags
#define GPIO_CLEAR_DATA_OUT 0x190
#define GPIO_SET_DATA_OUT 0x194
#define GPIO_DATA_IN 0x138

//========================================Interrupt Stuff============================================
/* Interrupt numbers  (spruh73l.pdf S.465 ff.) */
#define INTR_GPIO_PORT0 97
#define INTR_GPIO_PORT1 99
#define INTR_GPIO_PORT2 33

/* GPIO port addresses (spruh73l.pdf S.177 ff.) */
#define GPIO_PORT0 0x44E07000
#define GPIO_PORT1 0x4804C000
#define GPIO_PORT2 0x481AC000

/* GPIO port registers length */
#define GPIO_REGISTER_LENGHT 0x1000

/* GPIO register offsets (spruh73l.pdf S.4877) */
#define GPIO_LEVELDETECT0 0x140
#define GPIO_LEVELDETECT1 0x144
#define GPIO_RISINGDETECT 0x148
#define GPIO_FALLINGDETECT 0x14C

#define GPIO_IRQSTATUS_0 0x2C
#define GPIO_IRQSTATUS_1 0x30
#define GPIO_IRQSTATUS_SET_0 0x34
#define GPIO_IRQSTATUS_SET_1 0x38

// /* Helper macros */
#define BIT_MASK(x) (0x1 << (x))

#endif /* SRC_UTILS_GPIO_H_ */
