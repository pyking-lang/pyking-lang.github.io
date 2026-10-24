(* Generated from math.pyk by the Pyking compiler. Do not edit. *)
(* Target: ocaml4.14. The module 'math' of the program; compile it
   before the ones that import it. *)

let pyk_truncate x =
  if Float.is_nan x then 0
  else
    let t = Float.trunc x in
    if t < -2147483648.0 || t > 2147483647.0 then 0 else int_of_float t

let pi = 3.141592653589793

let tau = 6.283185307179586

let e = 2.718281828459045

let inf = Stdlib.infinity

let nan = 0.0 /. 0.0

let is_nan x = if x = x then false else true

let is_finite x = x -. x = 0.0

let to_radians deg = deg *. pi /. 180.0

let to_degrees rad = rad *. 180.0 /. pi

let int__abs x = if x < 0 then -x else x

let float__abs x = if x <= 0.0 then 0.0 -. x else x

let int__min x y = if y < x then y else x

let float__min x y =
  if is_nan x then x
  else if is_nan y then y
  else if y < x then y
  else x

let int__max x y = if y > x then y else x

let float__max x y =
  if is_nan x then x
  else if is_nan y then y
  else if y > x then y
  else x

let int__clamp x low high = int__max low (int__min x high)

let float__clamp x low high = float__max low (float__min x high)

let int__sign x = if x < 0 then -1 else if x > 0 then 1 else 0

let float__sign x =
  if x < 0.0 then -.1.0
  else if x > 0.0 then 1.0
  else if x = 0.0 then 0.0
  else x

let int__mod x y =
  let r = x - x / y * y in
  if r < 0 then (if y > 0 then r + y else r)
  else if r > 0 then (if y < 0 then r + y else r)
  else 0

let float__mod x y =
  let r = x -. y *. Math_external.host_floor (x /. y) in
  if y > 0.0 then (if r >= y then 0.0 else r)
  else if r <= y then 0.0
  else r

let sin angle = Math_external.host_sin angle

let cos angle = Math_external.host_cos angle

let tan angle = Math_external.host_tan angle

let asin x = Math_external.host_asin x

let acos x = Math_external.host_acos x

let atan x = Math_external.host_atan x

let atan2 y x = Math_external.host_atan2 y x

let sinh x = Math_external.host_sinh x

let cosh x = Math_external.host_cosh x

let tanh x = Math_external.host_tanh x

let exp x = Math_external.host_exp x

let log x = Math_external.host_log x

let log2 x = Math_external.host_log2 x

let log10 x = Math_external.host_log10 x

let sqrt x = Math_external.host_sqrt x

let cbrt x =
  let root = Math_external.host_cbrt x in
  let nearest = Math_external.host_floor (root +. 0.5) in
  if nearest *. nearest *. nearest = x then nearest else root

let pow x y = Math_external.host_pow x y

let hypot x y = Math_external.host_hypot x y

let distance x1 y1 x2 y2 =
  Math_external.host_hypot (x2 -. x1) (y2 -. y1)

let floor x = pyk_truncate (Math_external.host_floor x)

let ceil x = pyk_truncate (Math_external.host_ceil x)

let trunc x = pyk_truncate (Math_external.host_trunc x)

let round x =
  let whole = Math_external.host_trunc x in
  let part = x -. whole in
  if part >= 0.5 then pyk_truncate (whole +. 1.0)
  else if part <= -.0.5 then pyk_truncate (whole -. 1.0)
  else pyk_truncate whole

let rec euclid x y = if y = 0 then x else euclid y (x - x / y * y)

let gcd x y = euclid (int__abs x) (int__abs y)

let lcm x y =
  if x = 0 then 0 else if y = 0 then 0 else int__abs (x / gcd x y * y)

let lerp a b t = a +. (b -. a) *. t

let map_range x from_low from_high to_low to_high =
  to_low +. (x -. from_low) *. (to_high -. to_low) /. (from_high -. from_low)
