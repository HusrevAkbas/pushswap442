CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

LIBFTA := libcheck

SRC := list.c moves.c push_swap.c stacks.c utils.c moves_more.c stacks_more.c

OBJ := $(SRC:.c=.o)

NAME := push_swap
#| paste - - - - - - -
TEST1 = ./${NAME} 96 88 73 25 79 4 97 7 16 12 84 52 31 71 70 99 11 17 87 66 62 33 34 6 15 21 94 77 48 92 20 60 69 9 24 40 85 61 63 82 55 91 14 5 26 28 75 3 67 22 23 59 58 86 45 10 90 35 2 8 101 100 53 50 13 56 39 95 78 32 1 93 37 51 80 29 57 36 18 64 27 68 42 44 54 0 98 72 38 76 49 19 30 74 47 43 81 83 89 65
TEST100 = ./${NAME} 31 19 26 4 18 12 63 23 22 100 14 87 44 74 77 86 53 33 29 46 41 34 16 60 58 3 62 28 43 97 21 66 57 90 98 42 6 50 52 24 79 88 38 45 55 92 83 40 9 80 32 71 82 93 54 85 17 70 94 49 10 47 76 78 68 65 7 56 48 64 36 39 95 81 96 84 75 35 8 1 61 51 91 89 72 69 2 59 67 99 73 5 27 20 13 37 11 30 15 25
TEST3 = ./${NAME} "9 11 10"
TEST500 = ./${NAME} 191 445 17 131 348 216 335 353 374 355 388 347 386 343 152 92 78 357 383 182 299 67 381 363 292 10 205 54 209 230 306 341 332 224 476 50 489 312 178 466 494 200 359 22 295 197 105 264 493 401 128 138 16 323 75 467 419 331 118 236 421 377 402 367 121 424 305 245 408 471 391 296 26 361 233 61 159 318 378 340 114 289 255 382 443 93 88 282 164 35 117 262 339 321 313 300 179 180 3 420 239 322 153 288 396 372 266 260 155 186 464 307 68 309 474 277 379 72 478 403 12 52 135 87 293 426 85 110 435 234 80 9 278 84 364 286 194 498 143 324 434 90 2 316 365 63 19 195 11 56 5 373 73 124 246 453 415 144 409 429 107 211 387 198 34 389 436 212 15 398 167 256 38 136 275 146 158 141 290 366 129 439 163 130 171 280 96 106 82 71 317 168 111 254 410 219 119 451 490 247 192 94 287 342 76 252 116 481 497 356 126 166 148 51 177 400 39 268 284 213 349 329 487 407 482 242 89 500 297 283 483 173 103 99 127 101 485 157 279 145 183 215 308 228 226 66 456 55 479 151 468 24 104 4 172 352 97 6 394 452 227 480 315 354 345 298 416 113 13 69 149 488 112 190 430 350 397 259 418 263 176 432 150 336 455 174 64 457 123 454 49 404 433 77 412 102 281 427 360 326 30 7 154 411 469 450 189 333 390 91 311 229 204 251 202 334 41 74 58 53 393 431 60 406 265 449 181 303 36 18 156 43 238 162 327 291 477 223 325 29 414 459 465 475 184 470 346 276 472 351 338 132 23 218 272 98 375 491 486 371 304 237 417 32 33 25 125 444 47 188 428 462 133 441 370 448 310 206 384 46 440 45 139 232 8 437 385 458 368 392 37 399 27 250 65 261 425 170 217 44 48 28 169 95 100 244 413 362 243 269 249 380 328 473 267 294 231 273 203 499 463 369 201 42 225 109 220 221 405 319 70 122 20 495 376 210 193 175 187 79 253 442 301 274 395 160 1 147 57 222 320 83 31 241 461 271 142 240 81 134 496 438 40 108 86 337 314 270 185 447 214 165 14 21 330 422 492 207 423 161 120 484 62 235 446 257 248 258 344 196 137 59 302 140 208 460 358 199 115 285
TEST2 = ./${NAME} -3 4 12 33 77 || true
TEST = ${TEST500}

all: ${NAME} clean
#	-${TEST2}
	-${TEST}

${NAME}: ${OBJ} ${LIBFTA}
	@-cc -g ${CFLAGS} ${OBJ} -L ${LIBFT} -lft -o ${NAME}

${OBJ}: ${SRC}
	@- cc -g -c ${CFLAGS} ${SRC}

${LIBFTA}:
	@- ${MAKE} -C ${LIBFT} bonus clean
	touch ${LIBFTA}

clean:
#@ ${MAKE} -C ${LIBFT} clean
	@- rm -f ${OBJ}

fclean: clean
	@ ${MAKE} -C ${LIBFT} fclean
	rm -f ${NAME} ${LIBFTA}

re: fclean all

val: all
	@valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ${TEST}

fun: all
	@funcheck ${TEST}

run:
	./${NAME}