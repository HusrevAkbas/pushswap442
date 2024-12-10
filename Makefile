CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

LIBFTA := libcheck

SRC := list.c moves.c push_swap.c stacks.c utils.c moves_more.c stacks_more.c

OBJ := $(SRC:.c=.o)

NAME := push_swap
#| paste - - - - - - -
TEST1 = ./${NAME} 33 26 86 60 37 61 77 79 7 58 72 34 35 75 4 64 14 67 31 57 96 38 78 5 19 36 90 98 52 88 66 24 22 59 55 63 20 99 94 27 32 6 95 89 45 3 23 62 16 68 40 87 65 92 11 17 84 53 100 56 8 71 46 50 1 15 82 9 13 30 81 39 44 42 85 43 12 41 76 2 51 93 80 83 97 91 25 21 49 10 73 47 74 70 54 18 29 69 48 28
TEST100 = ./${NAME} 34 95 52 61 64 15 42 59 62 29 68 92 76 32 6 63 24 71 9 36 58 49 14 30 16 40 50 28 96 51 83 48 54 5 99 12 45 20 90 85 46 66 18 100 82 87 11 31 80 70 27 73 93 78 41 72 10 35 2 81 53 97 1 43 86 74 38 23 55 25 98 67 94 88 3 37 89 21 33 17 47 7 56 65 69 60 84 39 77 13 91 44 19 8 4 22 26 79 57 75
TEST3 = ./${NAME} "9 11 10 7"
TEST500 = ./${NAME} 398 335 270 242 173 125 67 245 432 321 488 69 452 70 476 182 477 492 318 407 116 283 221 135 370 430 183 297 284 401 499 248 32 243 54 386 273 469 165 472 304 394 43 90 159 168 93 491 213 315 392 126 63 22 112 396 193 233 444 53 148 184 308 466 387 207 286 72 373 374 294 7 203 307 445 1 376 264 12 481 111 114 453 151 156 209 349 47 147 484 437 197 214 44 102 212 2 172 342 261 211 474 169 98 65 26 415 279 202 237 247 6 463 84 96 201 161 470 23 465 186 313 206 384 119 427 31 393 37 60 106 388 366 456 380 417 97 418 185 104 49 14 254 438 267 314 232 351 425 139 337 219 20 64 234 29 423 327 391 218 338 58 181 489 223 158 163 136 397 109 375 486 92 222 59 191 134 300 320 133 46 255 131 334 360 362 149 424 480 405 94 81 420 457 217 299 194 155 421 103 256 16 497 118 436 390 346 188 3 238 369 305 195 448 408 121 192 419 455 395 141 336 459 85 268 317 251 127 439 122 30 239 117 38 377 123 124 75 145 347 263 389 52 371 495 471 311 51 428 475 196 483 175 252 190 210 365 226 132 19 293 319 441 24 288 62 341 412 230 250 95 5 372 449 189 87 227 385 302 467 10 404 458 278 416 399 487 498 199 120 298 45 229 228 414 35 450 113 177 89 178 435 66 160 333 295 345 105 154 325 400 34 40 446 41 378 292 285 257 324 258 434 326 128 460 79 411 316 274 216 275 28 61 381 48 153 440 482 332 259 356 240 17 406 36 367 493 429 344 200 461 379 157 166 15 363 331 198 410 296 266 260 130 433 354 107 358 403 73 339 322 80 361 171 350 454 21 287 146 143 236 25 409 4 9 56 289 323 208 402 447 355 262 204 282 13 451 231 76 215 170 413 269 312 187 164 468 329 246 167 352 224 479 303 478 494 71 306 357 110 179 27 91 50 129 68 348 11 442 330 235 364 115 272 485 383 368 496 473 265 310 142 301 464 176 340 225 426 57 174 205 276 490 162 281 249 82 18 291 99 443 108 500 277 280 88 144 42 353 244 55 101 422 138 86 152 253 74 328 462 140 39 150 137 8 83 78 431 77 309 343 359 220 100 271 180 33 290 241 382
TEST2 = ./${NAME} -3 4 12 33 77 || true
TEST = ${TEST100}

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