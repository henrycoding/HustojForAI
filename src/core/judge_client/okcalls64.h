/*
 * 
 *
 * This file is part of HUSTOJ.
 *
 * HUSTOJ is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * HUSTOJ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HUSTOJ. if not, see <http://www.gnu.org/licenses/>.
 */

int LANG_CV[256] = {0,1,2,3,4,5,8,9,11,12,21,59,63,89,158,231,240, SYS_time, SYS_read, SYS_uname, SYS_write, SYS_open,
		SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_munmap, SYS_mprotect,
		SYS_mmap, SYS_fstat, SYS_set_thread_area, 252, SYS_arch_prctl, 0 };

int LANG_PV[256] = {0,1,2,3,4,9,11,13,16,59,89,97,201,231,SYS_open, SYS_set_thread_area, SYS_brk, SYS_read,
		SYS_uname, SYS_write, SYS_execve, SYS_ioctl, SYS_readlink, SYS_mmap,
		SYS_rt_sigaction, SYS_getrlimit, 252, 191, 158, 231, SYS_close, 318,
		SYS_exit_group, SYS_munmap, SYS_time, 4, 0 };

int LANG_JV[256] = { 0,2,3,4,5,9,10,11,12,13,14,21,56,59,89,97,104,158,202,218,231,273,257, 
		61, 22, 6, 33, 8, 13, 16, 111, 110, 39, 79, SYS_fcntl,
		SYS_getdents64, SYS_getrlimit, SYS_rt_sigprocmask, SYS_futex, SYS_read,
		SYS_mmap, SYS_stat, SYS_open, SYS_close, SYS_execve, SYS_access,
		SYS_brk, SYS_readlink, SYS_munmap, SYS_close, SYS_uname, SYS_clone,
		SYS_uname, SYS_mprotect, SYS_rt_sigaction, SYS_getrlimit, SYS_fstat,
		SYS_getuid, SYS_getgid, SYS_geteuid, SYS_getegid, SYS_set_thread_area,
		SYS_set_tid_address, SYS_set_robust_list, SYS_exit_group, 158, 0 };

int LANG_RV[256] = { 0,1,2,3,4,5,9,10,12,13,14,16,21,22,56,59,72,97,98,107,108,131,158,202,218,231,273
		,96, 340, 4, 126, SYS_access, SYS_arch_prctl, SYS_brk,
		SYS_close, SYS_execve, SYS_exit_group, SYS_fstat, SYS_futex,
		SYS_getegid, SYS_geteuid, SYS_getgid, SYS_getuid, SYS_getrlimit,
		SYS_mmap, SYS_mprotect, SYS_munmap, SYS_open, SYS_read,
		SYS_rt_sigaction, SYS_rt_sigprocmask, SYS_set_robust_list,
		SYS_set_tid_address, SYS_write, 0 };

int LANG_BV[256] = { 0,1,2,3,4,5,8,9,10,12,13,14,16,21,33,39,59,63,72,79,97,102,104,107,108,110,111,158,231,
		96, 22, 61, 56, 42, 41, 79, 158, 117, 60, 39, 102, 191,
		183, SYS_access, SYS_arch_prctl, SYS_brk, SYS_close, SYS_dup2,
		SYS_execve, SYS_exit_group, SYS_fcntl, SYS_fstat, SYS_getegid,
		SYS_geteuid, SYS_getgid, SYS_getpgrp, SYS_getpid, SYS_getppid,
		SYS_getrlimit, SYS_getuid, SYS_ioctl, SYS_lseek, SYS_mmap, SYS_mprotect,
		SYS_munmap, SYS_open, SYS_read, SYS_rt_sigaction, SYS_rt_sigprocmask,
		SYS_stat, SYS_uname, SYS_write, 14, 0 };

int LANG_YV[513] = //{0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 , 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 87 , 88 , 89 , 90 , 91 , 92 , 93 , 94 , 95 , 96 , 97 , 98 , 99 , 100 , 101 , 102 , 103 , 104 , 105 , 106 , 107 , 108 , 109 , 110 , 111 , 112 , 113 , 114 , 115 , 116 , 117 , 118 , 119 , 120 , 121 , 122 , 123 , 124 , 125 , 126 , 127 , 128 , 129 , 130 , 131 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 141 , 142 , 143 , 144 , 145 , 146 , 147 , 148 , 149 , 150 , 151 , 152 , 153 , 154 , 155 , 156 , 157 , 158 , 159 , 160 , 161 , 162 , 163 , 164 , 165 , 166 , 167 , 168 , 169 , 170 , 171 , 172 , 173 , 174 , 175 , 176 , 177 , 178 , 179 , 180 , 181 , 182 , 183 , 184 , 185 , 186 , 187 , 188 , 189 , 190 , 191 , 192 , 193 , 194 , 195 , 196 , 197 , 198 , 199 , 200 , 201 , 202 , 203 , 204 , 205 , 206 , 207 , 208 , 209 , 210 , 211 , 212 , 213 , 214 , 215 , 216 , 217 , 218 , 219 , 220 , 221 , 222 , 223 , 224 , 225 , 226 , 227 , 228 , 229 , 230 , 231 , 232 , 233 , 234 , 235 , 236 , 237 , 238 , 239 , 240 , 241 , 242 , 243 , 244 , 245 , 246 , 247 , 248 , 249 , 250 , 251 , 252 , 253 , 254 , 255 , 256 , 257 , 258 , 259 , 260 , 261 , 262 , 263 , 264 , 265 , 266 , 267 , 268 , 269 , 270 , 271 , 272 , 273 , 274 , 275 , 276 , 277 , 278 , 279 , 280 , 281 , 282 , 283 , 284 , 285 , 286 , 287 , 288 , 289 , 290 , 291 , 292 , 293 , 294 , 295 , 296 , 297 , 298 , 299 , 300 , 301 , 302 , 303 , 304 , 305 , 306 , 307 , 308 , 309 , 310 , 311 , 312 , 313 , 314 , 315 , 316 , 317 , 318 , 319 , 320 , 321 , 322 , 323 , 324 , 325 , 326 , 327 , 328 , 329 , 330 , 331 , 332 , 333 , 334 , 335 , 336 , 337 , 338 , 339 , 340 , 341 , 342 , 343 , 344 , 345 , 346 , 347 , 348 , 349 , 350 , 351 , 352 , 353 , 354 , 355 , 356 , 357 , 358 , 359 , 360 , 361 , 362 , 363 , 364 , 365 , 366 , 367 , 368 , 369 , 370 , 371 , 372 , 373 , 374 , 375 , 376 , 377 , 378 , 379 , 380 , 381 , 382 , 383 , 384 , 385 , 386 , 387 , 388 , 389 , 390 , 391 , 392 , 393 , 394 , 395 , 396 , 397 , 398 , 399 , 400 , 401 , 402 , 403 , 404 , 405 , 406 , 407 , 408 , 409 , 410 , 411 , 412 , 413 , 414 , 415 , 416 , 417 , 418 , 419 , 420 , 421 , 422 , 423 , 424 , 425 , 426 , 427 , 428 , 429 , 430 , 431 , 432 , 433 , 434 , 435 , 436 , 437 , 438 , 439 , 440 , 441 , 442 , 443 , 444 , 445 , 446 , 447 , 448 , 449 , 450 , 451 , 452 , 453 , 454 , 455 , 456 , 457 , 458 , 459 , 460 , 461 , 462 , 463 , 464 , 465 , 466 , 467 , 468 , 469 , 470 , 471 , 472 , 473 , 474 , 475 , 476 , 477 , 478 , 479 , 480 , 481 , 482 , 483 , 484 , 485 , 486 , 487 , 488 , 489 , 490 , 491 , 492 , 493 , 494 , 495 , 496 , 497 , 498 , 499 , 500 , 501 , 502 , 503 , 504 , 505 , 506 , 507 , 508 , 509 , 510 , 511};
    { 0,32,72,131,1,2,3,4,5,6,8,9,10,11,12,13,14,16,21,59,78,79,89,97,102,104,107,108,158,202,218,231,257,273
			, 41, 42, 146, SYS_mremap, 158, 117, 60, 39, 102, 191,
        318,99,
		SYS_access, SYS_arch_prctl, SYS_brk, SYS_close, SYS_execve,
		SYS_exit_group, SYS_fcntl, SYS_fstat, SYS_futex, SYS_getcwd,
		SYS_getdents, SYS_getegid, SYS_geteuid, SYS_getgid, SYS_getrlimit,
		SYS_getuid, SYS_ioctl, SYS_lseek, SYS_lstat, SYS_mmap, SYS_mprotect,
		SYS_munmap, SYS_open, SYS_read, SYS_readlink, SYS_rt_sigaction,
		SYS_rt_sigprocmask, SYS_set_robust_list, SYS_set_tid_address, SYS_stat,
		SYS_write, 0 };
/* */
int LANG_PHV[256] = { 0,1,2,3,4,5,6,8,9,10,11,12,13,14,16,21,59,79,97,158,202,218,231,257,273,
		257, 20, 146, 78, 158, 117, 60, 39, 102, 191, SYS_access,
		SYS_brk, SYS_clone, SYS_close, SYS_execve, SYS_exit_group, SYS_fcntl,
		SYS_fstat, SYS_futex, SYS_getcwd, SYS_getdents64, SYS_getrlimit,
		SYS_gettimeofday, SYS_ioctl, SYS_lseek, SYS_lstat, SYS_mmap,
		SYS_mprotect, SYS_munmap, SYS_open, SYS_read, SYS_readlink,
		SYS_rt_sigaction, SYS_rt_sigprocmask, SYS_set_robust_list,
		SYS_set_thread_area, SYS_set_tid_address, SYS_stat, SYS_time, SYS_uname,
		SYS_write, 0 };

int LANG_PLV[256] = {0,1,2,3,4,5,8,9,10,12,13,14,16,21,59,72,89,97,102,104,107,108,158,202,218,231,273,
		 96, 78, 158, 117, 60, 39, 102, 191, SYS_access, SYS_brk,
		SYS_close, SYS_execve, SYS_exit_group, SYS_fcntl, SYS_fstat, SYS_futex,
		SYS_getegid, SYS_geteuid, SYS_getgid, SYS_getrlimit, SYS_getuid,
		SYS_ioctl, SYS_lseek, SYS_mmap, SYS_mprotect, SYS_munmap, SYS_open,
		SYS_read, SYS_readlink, SYS_rt_sigaction, SYS_rt_sigprocmask,
		SYS_set_robust_list, SYS_set_thread_area, SYS_set_tid_address, SYS_stat,
		SYS_time, SYS_uname, SYS_write, 0 };

int LANG_CSV[256] = {0,1,2,3,4,5,8,9,10,11,12,13,14,16,21,24,41,42,56,59,63,72,78,79,89,97
		,102,131,137,158,202,204,218,229,231,234,257,273, 257, 141, 95, 64, 65, 66
		, 83, 24, 42, 41, 158, 117, 60,
		39, 102, 191, SYS_access, SYS_brk, SYS_chmod, SYS_clock_getres,
		SYS_clock_gettime, SYS_clone, SYS_close, SYS_execve, SYS_exit_group,
		SYS_fcntl, SYS_fstat, SYS_ftruncate, SYS_futex, SYS_getcwd,
		SYS_getdents, SYS_geteuid, SYS_getpid, SYS_getppid, SYS_getrlimit,
		SYS_gettimeofday, SYS_getuid, SYS_ioctl, SYS_lseek, SYS_lstat, SYS_mmap,
		SYS_mprotect, SYS_mremap, SYS_munmap, SYS_open, SYS_read, SYS_readlink,
		SYS_rt_sigaction, SYS_rt_sigprocmask, SYS_sched_getaffinity,
		SYS_sched_getparam, SYS_sched_get_priority_max,
		SYS_sched_get_priority_min, SYS_sched_getscheduler, SYS_set_robust_list,
		SYS_set_thread_area, SYS_set_tid_address, SYS_sigaltstack, SYS_stat,
		SYS_statfs, SYS_tgkill, SYS_time, SYS_uname, SYS_unlink, SYS_write, 0 };

int LANG_OV[256] = { 0,1,2,3,4,5,9,10,12,21,59,158,231, 102, 191, SYS_access, SYS_brk, SYS_close,
		SYS_execve, SYS_exit_group, SYS_fstat, SYS_futex, SYS_getcwd,
		SYS_getrlimit, SYS_gettimeofday, SYS_mmap, SYS_mprotect, SYS_munmap,
		SYS_open, SYS_read, SYS_readlink, SYS_rt_sigaction, SYS_rt_sigprocmask,
		SYS_set_robust_list, SYS_set_thread_area, SYS_set_tid_address,
		SYS_uname, SYS_write, 0 };

int LANG_BASICV[256] = { 0,1,2,3,4,5,9,10,12,13,14,16,21,59,97,158,173,202,218,231,273,
		101, 54, 122, 175, 174, 240, 311, 258, 243, 6, 197,
		252, 146, 195, 192, 33, 45, 125, 191, SYS_access, SYS_brk, SYS_close,
		SYS_execve, SYS_exit_group, SYS_fstat, SYS_futex, SYS_getrlimit,
		SYS_ioctl, SYS_ioperm, SYS_mmap, SYS_open, SYS_read, SYS_rt_sigaction,
		SYS_rt_sigprocmask, SYS_set_robust_list, SYS_set_thread_area,
		SYS_set_tid_address, SYS_stat, SYS_uname, SYS_write, 0 };

int LANG_SV[256] = { 1, 23, 100, 61, 22, 6, 33, 8, 13, 16, 111, 110, 39, 79,
		SYS_fcntl, SYS_getdents64, SYS_getrlimit, SYS_rt_sigprocmask, SYS_futex,
		SYS_read, SYS_mmap, SYS_stat, SYS_open, SYS_close, SYS_execve,
		SYS_access, SYS_brk, SYS_readlink, SYS_munmap, SYS_close, SYS_uname,
		SYS_clone, SYS_uname, SYS_mprotect, SYS_rt_sigaction, SYS_getrlimit,
		SYS_fstat, SYS_getuid, SYS_getgid, SYS_geteuid, SYS_getegid,
		SYS_set_thread_area, SYS_set_tid_address, SYS_set_robust_list,
		SYS_exit_group, 158, 0 };

int LANG_LUAV[256]={0,1,2,3,4,5,9,10,11,12,13,21,59,158,231,292,0};
int LANG_JSV[256]={0,1,2,3,4,5,6,9,10,11,12,13,14,16,21,56,59,79,89,96,97,158,186,202,218,228,231,232,233,273,290,291,293,0};
int LANG_GOV[256]={0,1,9,11,13,14,56,59,131,158,202,204,228,231,0};



int LANG_JARV[256] = { 0,2,3,4,5,9,10,11,12,13,14,21,56,59,89,97,104,158,202,218,231,273,257, 
		61, 22, 6, 33, 8, 13, 16, 111, 110, 39, 79, SYS_fcntl,
		SYS_getdents64, SYS_getrlimit, SYS_rt_sigprocmask, SYS_futex, SYS_read,
		SYS_mmap, SYS_stat, SYS_open, SYS_close, SYS_execve, SYS_access,
		SYS_brk, SYS_readlink, SYS_munmap, SYS_close, SYS_uname, SYS_clone,
		SYS_uname, SYS_mprotect, SYS_rt_sigaction, SYS_getrlimit, SYS_fstat,
		SYS_getuid, SYS_getgid, SYS_geteuid, SYS_getegid, SYS_set_thread_area,
		SYS_set_tid_address, SYS_set_robust_list, SYS_exit_group, 158, 0 };