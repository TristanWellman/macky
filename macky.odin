/*Copyright (c) 2025 Tristan Wellman

  Macky bindings for odin
  
*/

package macky

import "core:fmt"
import "core:c"

foreign import mky "../libmacky.a"

MKY_BOOL :: c.int

MKY_MAX_ARR_SIZE :: 1024
_MKY_FBSTEP 1024

MKY_TRUE :: 1
MKY_FALSE :: 2

mky_array :: struct {
	array: rawptr,
	array_length: c.int
}

mky_data :: struct {
	file: ^c.FILE,
	filebuf: cstring,
	fsize: c.int,
	fcap: c.int
}

foreign mky {

	MKY_ARR :: proc() ---
	
	@(link_name="mky_init")
	init :: proc(filename: cstring) -> ^mky_data ---

	@(link_name="mky_close")
	close :: proc(data: ^mky_data) ---

	@(link_name="mky_getIntArrayAt")
	getIntArrayAt :: proc(section: cstring, itemName: cstring) -> mky_array ---

	@(link_name="mky_getIntAt")
	getIntAt :: proc(section: cstring, itemName: cstring) -> c.int ---

	@(link_name="mky_getFloatAt")
	getFloatAt :: proc(section: cstring, itemName: cstring) -> c.float ---

	@(link_name="mky_getStrAt")
	getStrAt :: proc(section: cstring, itemName: cstring) -> cstring ---

	@(link_name="mky_getBoolAt")
	getBoolAt :: proc(section: cstring, itemName: cstring) -> MKY_BOOL ---


}
