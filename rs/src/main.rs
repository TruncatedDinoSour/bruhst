use std::f64::consts::PI;
use rand::Rng;
use std::fs::File;
use std::io::prelude::*;

const G: f64 = 6.6743e-11;
const N: usize = 10000;
const BODIES_N: usize = 20;
const DT: f64 = 0.1;

fn io(data: &[i32]) {
    let mut file = File::create("/tmp/.tmpfile").unwrap();

    for idx in 0..N {
        file.write(&[data[idx] as u8]).unwrap();
    }

    file.flush().unwrap();
    std::fs::remove_file("/tmp/.tmpfile").unwrap();
}

fn fib(n: i32) -> i32 {
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}

fn swap(arr: &mut [i32], i: usize, j: usize) {
    let tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

}

fn bubble_sort(arr: &mut [i32]) {
    let n = arr.len();

    for i in 0..n {
        for j in 0..n - i - 1 {
            if arr[j] > arr[j + 1] {
                swap(arr, j, j + 1);
            }
        }
    }
}


#[derive(Copy)]
#[derive(Clone)]
struct Body {
    x: f64,
    y: f64,
    mass: f64,
    vx: f64,
    vy: f64,
}

fn compute_gravity(body1: &Body, body2: &Body) -> (f64, f64) {
    let dx = body2.x - body1.x;
    let dy = body2.y - body1.y;
    let distance = (dx * dx + dy * dy).sqrt();
    let force = G * body1.mass * body2.mass / (distance * distance);
    let angle = dy.atan2(dx);

    (force * angle.cos(), force * angle.sin())
}

fn simulate_bodies(bodies: &mut [Body]) {
    let mut force_x = [0.0; BODIES_N];
    let mut force_y = [0.0; BODIES_N];

    for idx in 0..BODIES_N {
        for jdx in idx + 1..BODIES_N {
            let (fx, fy) = compute_gravity(&bodies[idx], &bodies[jdx]);

            force_x[idx] += fx;
            force_y[idx] += fy;
            force_x[jdx] -= fx;
            force_y[jdx] -= fy;
        }
    }

    for idx in 0..BODIES_N {
        let body = &mut bodies[idx];
        let ax = force_x[idx] / body.mass;
        let ay = force_y[idx] / body.mass;

        body.vx += ax * DT;
        body.vy += ay * DT;
        body.x += body.vx * DT;
        body.y += body.vy * DT;
    }
}

fn main() {
    let mut bodies = [Body {
        x: 0.0,
        y: 0.0,
        mass: 5.972e24,
        vx: 0.0,
        vy: 0.0,
    }; BODIES_N];

    let mut rng = rand::thread_rng();

    let mut barr = vec![0i32; N];

    for i in 0..N {
        barr[i] = rand::random();
    }

    for idx in 1..BODIES_N {
        let mass = rng.gen_range(1.0..1e20);
        let distance = rng.gen_range(1e7..1e9);
        let angle = rng.gen_range(0.0..2.0 * PI);
        let x = distance * angle.cos();
        let y = distance * angle.sin();
        let speed = (G * bodies[0].mass / distance).sqrt();
        let vx = -speed * angle.sin();
        let vy = speed * angle.cos();

        bodies[idx] = Body {
            x,
            y,
            mass,
            vx,
            vy,
        };
    }

    let start_time = std::time::Instant::now();

    // io

    io(&barr);

    // fib

    fib(42);

    // bubblesort

    bubble_sort(&mut barr);

    // n-body sim

    for _ in 0..N {
        simulate_bodies(&mut bodies);
    }

    println!(
        "{}",
        (std::time::Instant::now() - start_time).as_secs_f64()
    );
}
