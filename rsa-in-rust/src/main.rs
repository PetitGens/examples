use data_encoding::BASE64;
use rsa::{Oaep, RsaPrivateKey, RsaPublicKey, pkcs1::EncodeRsaPrivateKey, rand_core::OsRng};
use sha2::Sha256;

fn padding() -> Oaep {
    Oaep::new::<Sha256>()
}

fn main() {
    let mut rng = OsRng;

    // Generate a 2048-bit RSA key pair
    let bits = 2048;
    let private_key = RsaPrivateKey::new(&mut rng, bits).expect("failed to generate key");

    println!(
        "Private Key:\n{}",
        BASE64.encode(
            private_key
                .to_pkcs1_der()
                .expect("Unable to encode private key")
                .as_bytes()
        )
    );

    let public_key = RsaPublicKey::from(&private_key);

    // Message to encrypt
    let plaintext = b"Hello, world!";

    // Encrypt
    let encrypted_data = public_key
        .encrypt(&mut rng, padding(), plaintext)
        .expect("failed to encrypt");

    println!("Encrypted:\n{}", BASE64.encode(&encrypted_data));

    // Decrypt
    let decrypted_data = private_key
        .decrypt(padding(), &encrypted_data)
        .expect("failed to decrypt");

    println!("Decrypted: {:?}", String::from_utf8_lossy(&decrypted_data));
}
