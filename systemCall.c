#include <linux/kernel.h>
#include <linux/random.h>
#include <linux/syscalls.h>

asmlinkage long sys_chainsmoker(void) {
    return get_random_int() % 6;
}