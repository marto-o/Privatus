# Privatus
**Privatus** is a **free and open-source VPN project** aimed at implementing a functional, encrypted network tunnel with a strong focus on **architectural clarity, separation between Control Plane and Data Plane**, and hands-on learning in networking and operating systems.

The project is currently in an **early development stage** and is initially intended for educational and experimental purposes, with the goal of evolving over time through community collaboration.

## Project Goals

The main goals of this project are:
 * To implement a **functional VPN** capable of tunneling IP traffic between a client and a server.
 * To design a clear architecture based on a strict separation of:
     - **Data Plane:** responsible for traffic transport and encryption.
     - **Control Plane:** responsible for configuration, authentication, and management.
 * To prioritize **simple, readable, and auditable code.**
 * To avoid reinventing critical components (cryptography, low-level networking) by relying on **existing libraries and well-known primitives.**
 * To serve as a **learning and experimentation platform** for students and developers interested in:
      - Computer networking
      - Operating systems
      - Low-level programming
      - Software architecture

## Project Status
***Status: Early stage / Experimental***
 * This project is **not ready for production use.**
 * The API, internal architecture, and protocol are subject to significant changes.
 * No guarantees are made regarding resistance against sophisticated adversaries or strong anonymity.

Current development focuses on:
 * Defining the overall system architecture.
 * Implementing a basic tunnel using TUN/TAP interfaces.
 * Establishing a solid Data Plane foundation before expanding the Control Plane.

## Scope and Non-Goals
This project aims to:
 * Be functional and usable in test and experimental scenarios.
 * Be fully open-source and modifiable.
 * Be understandable and auditable by third parties.
 * Grow incrementally with community feedback and contributions.

This project does not aim to (at least in its current stage):
 * Replace mature VPN solutions such as WireGuard or OpenVPN.
 * Provide strong anonymity or censorship resistance.
 * Offer commercial-grade or formally audited security.
 * Scale massively from the beginning.

## Contributing
Contributions are welcome and encouraged, especially in the form of:
 * Code reviews
 * Documentation improvements
 * Issue reports
 * Design suggestions
 * Small, incremental enhancements

Since the project is still in an early stage, contributors are encouraged to **open an issue before proposing large changes** to discuss the technical direction.
Further details will be provided in CONTRIBUTING.md.

## License 
This project is licensed under the GNU GENERAL PUBLIC LICENSE 3.0.

See the [LICENSE](LICENSE) file for details.

### Final Note
This project started as a personal initiative focused on learning and technical growth, but with the ambition of becoming a **clear, open, and collaborative implementation of a functional VPN.**

Constructive feedback and community participation are highly appreciated.


 
 
