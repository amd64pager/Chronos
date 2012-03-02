#include <hardware/timer.h>
#include <hardware/isr.h>
#include <screen/printk.h>

u32int _tick = 0;
u32int _seconds = 0;
u32int _minute = 0;
u32int _hour = 0;
u32int _day = 0;
u32int _frequency;
static void timer_callback(registers_t regs)
{
	_tick++;
	if(_tick%_frequency==0)
	{
		_seconds++;
		if(_seconds%60==0)
		{
			_minute++;
			if(_minute%60==0)
			{
				_hour++;
				if(_hour%24==0)
				{
					_day++;
				}
			}
		}
	}
}
void halt_s(int seconds)
{
	unsigned long eticks;

    eticks = seconds + _seconds;
    while(_seconds < eticks);
}
void init_timer(u32int frequency)
{
   register_interrupt_handler(IRQ0, &timer_callback);
   _frequency=frequency;
   // The value we send to the PIT is the value to divide it's input clock
   // (1193180 Hz) by, to get our required frequency. Important to note is
   // that the divisor must be small enough to fit into 16-bits.
   u32int divisor = 1193180 / frequency;

   // Send the command byte.
   koutb(0x43, 0x36);

   // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
   u8int l = (u8int)(divisor & 0xFF);
   u8int h = (u8int)( (divisor>>8) & 0xFF );

   // Send the frequency divisor.
   koutb(0x40, l);
   koutb(0x40, h);
}
