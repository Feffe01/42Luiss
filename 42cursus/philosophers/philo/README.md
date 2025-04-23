# Philosophers Project (42Cursus)

## 📘 Description

This project is a simulation of the classic concurrency problem: **The Dining Philosophers**. It is part of the 42 cursus and aims to explore thread creation and synchronization using mutexes.

## 🧠 The Problem

A number of philosophers sit at a table with a fork between each pair. They alternate between thinking, eating, and sleeping. A philosopher needs **two forks** to eat. The simulation must:

- Avoid starvation when possible (when a philosopher can't get access to both forks and eventually dies).
- Avoid deadlocks (when each philosopher holds one fork and waits forever for the other).
- Avoid data races (when multiple threads access shared data without proper synchronization).
- Respect precise timing with a margin of error of **±10ms**.

## 🛠️ Compilation & Cleaning Commands

```bash
make        # Compiles the program
make re     # Recompiles everything from scratch
make clean  # Removes object files
make fclean # Removes object files and the binary
```

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments:

- `number_of_philosophers`: total philosophers (and forks)
- `time_to_die`: time in ms before a philosopher dies without starting eating
- `time_to_eat`: eating time in ms
- `time_to_sleep`: sleeping time in ms
- `number_of_times_each_philosopher_must_eat` (optional): ends the simulation once each philosopher has eaten this many times

### Example:

```bash
./philo 5 800 200 200 10
```

## 💻 Code Details

### Data Structures

- Both philosophers and forks are implemented as linked lists for efficient memory usage.

### Thread Management

- Each philosopher is associated with its own thread.
- An additional thread runs in parallel, waking every millisecond to check if any philosopher has died or if all have completed their meals.

### Deadlock Avoidance

- Philosophers are split into two waves: even-indexed philosophers start at least 1ms after odd-indexed ones, to avoid deadlocks.

### Synchronization

- Forks are protected by mutexes to prevent data races.
- Philosopher statuses (eating, sleeping, thinking, dead, done) are updated and read under mutex protection to maintain consistency.

## 🔬 Testing

**💡 Tip:** To better understand how the program behaves over time, you can use this online visualizer:

🔗 [Philosophers Visualizer](https://nafuka11.github.io/philosophers-visualizer/)

Use `valgrind` to check for memory leaks:

```bash
valgrind --leak-check=full ./philo 5 800 200 200
```

⚠️ **Note:** Running the program under Valgrind significantly slows it down and may distort the timing. Use it only for memory leak detection, not for behavior or timing validation.

### 🧪 Some Cases to Try

- `./philo 1 800 200 200`: One philosopher with one fork (should die)
- `./philo 4 210 200 200`: Test for timing precision (no one should ever die)
- `./philo 5 800 200 200 3`: Check simulation stop after 3 meals
- `./philo 200 800 200 200`: Stress test (no one should ever die)

### 🧪 Edge Cases to Try

- `./philo 2 210 200 200`: Minimal pair, quick but fair execution, no one should ever die
- `./philo 6 0 200 200`: `time_to_die = 0`, an even philosopher should die instantly (because the odd ones start)
- `./philo 4 210 0 200`: `time_to_eat = 0`, no one should ever die or take the fork from a philosopher who was already waiting for it
- `./philo 4 210 200 0`: `time_to_sleep = 0`, no one should ever die or take the fork from a philosopher who was already waiting for it

## 📂 Files

- `Makefile`: handles compilation and cleaning commands
- `philo.h`: header file with data structures and function prototypes
- `main.c`: handles argument parsing and program startup
- `actions.c`: implements eating, sleeping, thinking behaviors
- `checkers.c`: monitors philosophers' state and ends the simulation if needed
- `ft_atoi.c`: custom atoi function used for argument parsing (taken from libft project)
- `handle_forks.c`: manages fork list creation
- `handle_philos.c`: manages philosopher list creation
- `initializer.c`: sets up forks and philosophers
- `status_changer.c`: changes and logs philosopher statuses
- `threads.c`: creates and joins all threads (philosophers + checker)
- `utils.c`: utility functions

## 👨‍💻 Author

- **Federico Giampà** (42 username: `fgiampa`)  [GitHub Profile](https://github.com/Feffe01)

## 🏁 License

This project is part of the 42 School curriculum and follows its norms and restrictions.
