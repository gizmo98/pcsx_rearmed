#include "vector_types.h"

#ifdef ASM_PROTOTYPES
#define compute_all_gradients compute_all_gradients_
#define update_texture_8bpp_cache_slice update_texture_8bpp_cache_slice_
#define setup_spans_up_left setup_spans_up_left_
#define setup_spans_up_right setup_spans_up_right_
#define setup_spans_down_left setup_spans_down_left_
#define setup_spans_down_right setup_spans_down_right_
#define setup_spans_up_a setup_spans_up_a_
#define setup_spans_up_b setup_spans_up_b_
#define setup_spans_down_a setup_spans_down_a_
#define setup_spans_down_b setup_spans_down_b_
#define setup_spans_up_down setup_spans_up_down_
#define setup_blocks_shaded_textured_dithered_unswizzled_indirect \
	setup_blocks_shaded_textured_dithered_unswizzled_indirect_
#define setup_blocks_shaded_untextured_dithered_unswizzled_indirect \
	setup_blocks_shaded_untextured_dithered_unswizzled_indirect_
#define setup_blocks_shaded_untextured_undithered_unswizzled_indirect \
	setup_blocks_shaded_untextured_undithered_unswizzled_indirect_
#define setup_blocks_shaded_untextured_dithered_unswizzled_direct \
	setup_blocks_shaded_untextured_dithered_unswizzled_direct_
#define setup_blocks_shaded_untextured_undithered_unswizzled_direct \
	setup_blocks_shaded_untextured_undithered_unswizzled_direct_
#define setup_blocks_unshaded_textured_dithered_unswizzled_indirect \
	setup_blocks_unshaded_textured_dithered_unswizzled_indirect_
#define setup_blocks_unshaded_untextured_undithered_unswizzled_indirect \
	setup_blocks_unshaded_untextured_undithered_unswizzled_indirect_
#define setup_blocks_unshaded_untextured_undithered_unswizzled_direct \
	setup_blocks_unshaded_untextured_undithered_unswizzled_direct_
#define setup_blocks_shaded_textured_dithered_swizzled_indirect \
	setup_blocks_shaded_textured_dithered_swizzled_indirect_
#define setup_blocks_unshaded_textured_dithered_swizzled_indirect \
	setup_blocks_unshaded_textured_dithered_swizzled_indirect_
#define texture_blocks_untextured texture_blocks_untextured_
#define texture_blocks_4bpp texture_blocks_4bpp_
#define texture_blocks_8bpp texture_blocks_8bpp_
#define texture_blocks_16bpp texture_blocks_16bpp_
#define shade_blocks_shaded_textured_modulated_dithered_direct \
	shade_blocks_shaded_textured_modulated_dithered_direct_
#define shade_blocks_shaded_textured_modulated_undithered_direct \
	shade_blocks_shaded_textured_modulated_undithered_direct_
#define shade_blocks_unshaded_textured_modulated_dithered_direct \
	shade_blocks_unshaded_textured_modulated_dithered_direct_
#define shade_blocks_unshaded_textured_modulated_undithered_direct \
	shade_blocks_unshaded_textured_modulated_undithered_direct_
#define shade_blocks_shaded_textured_modulated_dithered_indirect \
	shade_blocks_shaded_textured_modulated_dithered_indirect_
#define shade_blocks_shaded_textured_modulated_undithered_indirect \
	shade_blocks_shaded_textured_modulated_undithered_indirect_
#define shade_blocks_unshaded_textured_modulated_dithered_indirect \
	shade_blocks_unshaded_textured_modulated_dithered_indirect_
#define shade_blocks_unshaded_textured_modulated_undithered_indirect \
	shade_blocks_unshaded_textured_modulated_undithered_indirect_
#define shade_blocks_textured_unmodulated_indirect \
	shade_blocks_textured_unmodulated_indirect_
#define shade_blocks_textured_unmodulated_direct \
	shade_blocks_textured_unmodulated_direct_
#define shade_blocks_unshaded_untextured_indirect \
	shade_blocks_unshaded_untextured_indirect_
#define shade_blocks_unshaded_untextured_direct shade_blocks_unshaded_untextured_direct_
#define blend_blocks_textured_average_off blend_blocks_textured_average_off_
#define blend_blocks_textured_average_on blend_blocks_textured_average_on_
#define blend_blocks_textured_add_off blend_blocks_textured_add_off_
#define blend_blocks_textured_add_on blend_blocks_textured_add_on_
#define blend_blocks_textured_subtract_off blend_blocks_textured_subtract_off_
#define blend_blocks_textured_subtract_on blend_blocks_textured_subtract_on_
#define blend_blocks_textured_add_fourth_off blend_blocks_textured_add_fourth_off_
#define blend_blocks_textured_add_fourth_on blend_blocks_textured_add_fourth_on_
#define blend_blocks_untextured_average_off blend_blocks_untextured_average_off_
#define blend_blocks_untextured_average_on blend_blocks_untextured_average_on_
#define blend_blocks_untextured_add_off blend_blocks_untextured_add_off_
#define blend_blocks_untextured_add_on blend_blocks_untextured_add_on_
#define blend_blocks_untextured_subtract_off blend_blocks_untextured_subtract_off_
#define blend_blocks_untextured_subtract_on blend_blocks_untextured_subtract_on_
#define blend_blocks_untextured_add_fourth_off blend_blocks_untextured_add_fourth_off_
#define blend_blocks_untextured_add_fourth_on blend_blocks_untextured_add_fourth_on_
#define blend_blocks_textured_unblended_off blend_blocks_textured_unblended_off_
#define blend_blocks_textured_unblended_on blend_blocks_textured_unblended_on_
#define texture_sprite_blocks_8bpp texture_sprite_blocks_8bpp_
#define setup_sprite_4bpp setup_sprite_4bpp_
#define setup_sprite_8bpp setup_sprite_8bpp_
#define setup_sprite_16bpp setup_sprite_16bpp_
#define setup_sprite_4bpp_4x setup_sprite_4bpp_4x_
#define setup_sprite_8bpp_4x setup_sprite_8bpp_4x_
#define setup_sprite_16bpp_4x setup_sprite_16bpp_4x_
#define setup_sprite_untextured setup_sprite_untextured_
#define setup_sprite_untextured_simple setup_sprite_untextured_simple_
#define scale2x_tiles8 scale2x_tiles8_
#endif

void compute_all_gradients(psx_gpu_struct * __restrict__ psx_gpu,
 const vertex_struct * __restrict__ a, const vertex_struct * __restrict__ b,
 const vertex_struct * __restrict__ c);

void update_texture_8bpp_cache_slice(psx_gpu_struct *psx_gpu,
 u32 texture_page);

void setup_spans_up_left(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_up_right(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_down_left(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_down_right(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_up_a(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_up_b(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_down_a(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_down_b(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);
void setup_spans_up_down(psx_gpu_struct *psx_gpu, vertex_struct *v_a,
 vertex_struct *v_b, vertex_struct *v_c);

void setup_blocks_shaded_textured_dithered_unswizzled_indirect(psx_gpu_struct
 *psx_gpu);

void setup_blocks_shaded_untextured_dithered_unswizzled_indirect(psx_gpu_struct
 *psx_gpu);
void setup_blocks_shaded_untextured_undithered_unswizzled_indirect(
 psx_gpu_struct *psx_gpu);
void setup_blocks_shaded_untextured_dithered_unswizzled_direct(psx_gpu_struct
 *psx_gpu);
void setup_blocks_shaded_untextured_undithered_unswizzled_direct(
 psx_gpu_struct *psx_gpu);

void setup_blocks_unshaded_textured_dithered_unswizzled_indirect(psx_gpu_struct
 *psx_gpu);
void setup_blocks_unshaded_untextured_undithered_unswizzled_indirect(
 psx_gpu_struct *psx_gpu);
void setup_blocks_unshaded_untextured_undithered_unswizzled_direct(
 psx_gpu_struct *psx_gpu);

void setup_blocks_shaded_textured_dithered_swizzled_indirect(psx_gpu_struct
 *psx_gpu);
void setup_blocks_unshaded_textured_dithered_swizzled_indirect(psx_gpu_struct
 *psx_gpu);

void texture_blocks_untextured(psx_gpu_struct *psx_gpu);
void texture_blocks_4bpp(psx_gpu_struct *psx_gpu);
void texture_blocks_8bpp(psx_gpu_struct *psx_gpu);
void texture_blocks_16bpp(psx_gpu_struct *psx_gpu);

void shade_blocks_shaded_textured_modulated_dithered_direct(psx_gpu_struct
 *psx_gpu);
void shade_blocks_shaded_textured_modulated_undithered_direct(psx_gpu_struct
 *psx_gpu);
void shade_blocks_unshaded_textured_modulated_dithered_direct(psx_gpu_struct
 *psx_gpu);
void shade_blocks_unshaded_textured_modulated_undithered_direct(psx_gpu_struct
 *psx_gpu);

void shade_blocks_shaded_textured_modulated_dithered_indirect(psx_gpu_struct
 *psx_gpu);
void shade_blocks_shaded_textured_modulated_undithered_indirect(psx_gpu_struct
 *psx_gpu);
void shade_blocks_unshaded_textured_modulated_dithered_indirect(psx_gpu_struct
 *psx_gpu);
void shade_blocks_unshaded_textured_modulated_undithered_indirect(psx_gpu_struct
 *psx_gpu);

void shade_blocks_textured_unmodulated_indirect(psx_gpu_struct *psx_gpu);
void shade_blocks_textured_unmodulated_direct(psx_gpu_struct *psx_gpu);

void shade_blocks_unshaded_untextured_indirect(psx_gpu_struct *psx_gpu);
void shade_blocks_unshaded_untextured_direct(psx_gpu_struct *psx_gpu);

void blend_blocks_textured_average_off(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_average_on(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_add_off(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_add_on(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_subtract_off(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_subtract_on(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_add_fourth_off(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_add_fourth_on(psx_gpu_struct *psx_gpu);

void blend_blocks_untextured_average_off(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_average_on(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_add_off(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_add_on(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_subtract_off(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_subtract_on(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_add_fourth_off(psx_gpu_struct *psx_gpu);
void blend_blocks_untextured_add_fourth_on(psx_gpu_struct *psx_gpu);

void blend_blocks_textured_unblended_off(psx_gpu_struct *psx_gpu);
void blend_blocks_textured_unblended_on(psx_gpu_struct *psx_gpu);

void texture_sprite_blocks_8bpp(psx_gpu_struct *psx_gpu);

void setup_sprite_4bpp(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u, s32 v,
 s32 width, s32 height, u32 color);
void setup_sprite_8bpp(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u, s32 v,
 s32 width, s32 height, u32 color);
void setup_sprite_16bpp(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u, s32 v,
 s32 width, s32 height, u32 color);

void setup_sprite_4bpp_4x(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u, s32 v,
 s32 width, s32 height, u32 color);
void setup_sprite_8bpp_4x(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u, s32 v,
 s32 width, s32 height, u32 color);
void setup_sprite_16bpp_4x(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u, s32 v,
 s32 width, s32 height, u32 color);

void setup_sprite_untextured(psx_gpu_struct *psx_gpu, s32 x, s32 y, s32 u,
 s32 v, s32 width, s32 height, u32 color);
void setup_sprite_untextured_simple(psx_gpu_struct *psx_gpu, s32 x, s32 y,
 s32 u, s32 v, s32 width, s32 height, u32 color);

void scale2x_tiles8(void *dst, const void *src, int w8, int h);

#ifdef ASM_PROTOTYPES
#undef compute_all_gradients
#undef update_texture_8bpp_cache_slice
#undef setup_spans_up_left
#undef setup_spans_up_right
#undef setup_spans_down_left
#undef setup_spans_down_right
#undef setup_spans_up_a
#undef setup_spans_up_b
#undef setup_spans_down_a
#undef setup_spans_down_b
#undef setup_spans_up_down
#undef setup_blocks_shaded_textured_dithered_unswizzled_indirect
#undef setup_blocks_shaded_untextured_dithered_unswizzled_indirect
#undef setup_blocks_shaded_untextured_undithered_unswizzled_indirect
#undef setup_blocks_shaded_untextured_dithered_unswizzled_direct
#undef setup_blocks_shaded_untextured_undithered_unswizzled_direct
#undef setup_blocks_unshaded_textured_dithered_unswizzled_indirect
#undef setup_blocks_unshaded_untextured_undithered_unswizzled_indirect
#undef setup_blocks_unshaded_untextured_undithered_unswizzled_direct
#undef setup_blocks_shaded_textured_dithered_swizzled_indirect
#undef setup_blocks_unshaded_textured_dithered_swizzled_indirect
#undef texture_blocks_untextured
#undef texture_blocks_4bpp
#undef texture_blocks_8bpp
#undef texture_blocks_16bpp
#undef shade_blocks_shaded_textured_modulated_dithered_direct
#undef shade_blocks_shaded_textured_modulated_undithered_direct
#undef shade_blocks_unshaded_textured_modulated_dithered_direct
#undef shade_blocks_unshaded_textured_modulated_undithered_direct
#undef shade_blocks_shaded_textured_modulated_dithered_indirect
#undef shade_blocks_shaded_textured_modulated_undithered_indirect
#undef shade_blocks_unshaded_textured_modulated_dithered_indirect
#undef shade_blocks_unshaded_textured_modulated_undithered_indirect
#undef shade_blocks_textured_unmodulated_indirect
#undef shade_blocks_textured_unmodulated_direct
#undef shade_blocks_unshaded_untextured_indirect
#undef shade_blocks_unshaded_untextured_direct
#undef blend_blocks_textured_average_off
#undef blend_blocks_textured_average_on
#undef blend_blocks_textured_add_off
#undef blend_blocks_textured_add_on
#undef blend_blocks_textured_subtract_off
#undef blend_blocks_textured_subtract_on
#undef blend_blocks_textured_add_fourth_off
#undef blend_blocks_textured_add_fourth_on
#undef blend_blocks_untextured_average_off
#undef blend_blocks_untextured_average_on
#undef blend_blocks_untextured_add_off
#undef blend_blocks_untextured_add_on
#undef blend_blocks_untextured_subtract_off
#undef blend_blocks_untextured_subtract_on
#undef blend_blocks_untextured_add_fourth_off
#undef blend_blocks_untextured_add_fourth_on
#undef blend_blocks_textured_unblended_off
#undef blend_blocks_textured_unblended_on
#undef texture_sprite_blocks_8bpp
#undef setup_sprite_4bpp
#undef setup_sprite_8bpp
#undef setup_sprite_16bpp
#undef setup_sprite_4bpp_4x
#undef setup_sprite_8bpp_4x
#undef setup_sprite_16bpp_4x
#undef setup_sprite_untextured
#undef setup_sprite_untextured_simple
#undef scale2x_tiles8
#endif
