#include <modules.h>

#include <screen.h>

#define NULL 0

module_t MODULE(char* name, char* description) {
	module_t mod;
	mod.usermode = false;
	mod.enabled = true;
	mod.initialized = false;
	mod.name = name;
	mod.description = description;
	return mod;
}

void INIT(module_t module) {
	kprintf("---initializing module ");
	kprintf(module.name);
	kprintf("\n");
	modules[count] = module;
	if(count == NULL) {
		count = 1;
	} else {
		count++;
	}
	module.initialized = true;
	kprintf(" \\->");
	putstr("done.\n", COLOR_GRN, COLOR_BLK);
}
void DISABLE(module_t module) {
	kprintf("---disabling module");
	kprintf(module.name);
	kprintf("\n");
	module.enabled = false;
	kprintf(" \\->done.\n");
}
void ENABLE(module_t module) {
	kprintf("---enabling module");
	kprintf(module.name);
	kprintf("\n");
	module.enabled = true;
	kprintf(" \\->done.\n");
}
void DEPS(module_t module, char** dependencies) {
	module.dependencies = dependencies;
}