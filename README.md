### gmsv_kill_on_hang

Creates a new thread that checks if `curtime` is incremented every 10 seconds, if it isn't it kills the process.

### Why
Because my server keeps hanging and doesn't get restarted automatically, this is annoying I'd rather have it restart automatically.

### Does it actually work
I don't know, so don't rely on this.

### public or x86-64
It should support both but I only tested on public.
Also on x86-64 it only supports x64.

### Windows
No.
