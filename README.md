# Macky

## About

Macky is a custom config file format that somewhat resembles COBOL.

This C library supports C89 standard code.

This is a small library for a much bigger project I'm working on.

## Macky Example

```
; This serves as a design testing/final design and test config file

CONFIG Test. 

SECTION ITEM.
	VALUE Name "ItemTest".
	VALUE Damage 100.
	;FUNCTION Effect ItemEffect.
END.

SECTION DROP.
	FLOAT Rarity 0.1. ; needs declared as float so it doesn't terminate with decimal
	VALUE ChestDrop TRUE.
	VALUE ChestDropLevel 25.
	VALUE MobDrop TRUE.
	VALUE MobDropLevel 15.
END.
```

### C example

```c
#include <stdio.h>
#include "macky.h"

int main() {
	mky_data *data = mky_init("test.mky");
	if(data==NULL) {
		printf("Error loading file!\n");
		return 0;
	}

	char *name = mky_getStrAt("ITEM", "Name");
	int damage = mky_getIntAt("ITEM", "Damage");
	float Rarity = mky_getFloatAt("DROP", "Rarity");

	printf("Name: %s\nDamage: %d\nRarity: %f", name, damage, Rarity);

	return 0;
}
```
