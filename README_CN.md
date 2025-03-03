[中文](https://github.com/WeCanSTU/AriesSDK/blob/main/README_CN.md) / [English](https://github.com/WeCanSTU/AriesSDK/blob/main/README.md)

# AriesSDK 简介

AriesSDK 是一款专为嵌入式 MCU（微控制器）设计的软件开发工具包，旨在简化设备与电脑之间的通信设置和固件更新过程。它提供了标准化的移植接口和模板，使开发人员能够快速实现关键功能，并确保设备能够在多平台环境中灵活操作。

## 主要功能

1. **统一接口与模板**
   - 提供标准的 I2C 和 IAP（In-Application Programming）移植接口和模板。这种统一性帮助开发者在不同项目和硬件平台上实现一致的功能，显著降低开发复杂度。

2. **USB-CDC 通信支持**
   - 用户只需按照 SDK 提供的模板实现 I2C 主设备驱动接口，即可让设备支持 USB-CDC（Communication Device Class）功能。
   - 通过 USB-CDC 接口，嵌入式设备可以作为虚拟串口设备连接到电脑，实现数据交换和调试，提升开发效率。

3. **跨平台固件更新（DFU）**
   - 在实现 I2C 接口后，继续实现 IAP 驱动接口，可使设备支持 DFU（Device Firmware Update）功能。
   - AriesSDK 通过免费提供的跨平台 TechSync 软件，实现了在 MacOS、Windows 和 Ubuntu 等多个操作系统上进行固件更新。这增强了设备的维护性和用户体验，确保用户在不同操作系统下都能顺利进行更新。

4. **DFU 的灵活性与安全性**
   - 专注于将固件数据完整搬运到用户实现的接口，至于固件数据的结构、加密与否、以及如何写入芯片 Flash，均由用户自行决定。
   - 这种设计使开发者可以根据具体需求，实现自定义的安全机制（如加密解密），以保护固件更新过程的安全性。

5. **多终端支持与协作能力**
   - 移植 AriesSDK 后，设备即可利用 TechSync 实现多终端支持：
     - **多用户访问**: 允许不同的电脑终端（本地或远程）同时对同一设备进行操作和数据通信。这显著提高了设备的协作和管理效率。
     - **远程固件更新**: 支持从不同地点的多终端对设备进行远程 DFU 操作，提升设备管理的灵活性。

## 适用场景

- **快速原型开发**: 提供的标准接口和模板有助于开发者快速创建原型，测试和验证产品功能。
- **多平台兼容**: 通过免费提供的 TechSync 软件，支持 MacOS、Windows 和 Ubuntu 的固件更新能力，使设备适用于多种操作系统环境，适合需要广泛兼容性的应用。
- **灵活的安全策略**: 允许用户定义固件的安全策略，包括数据加密和解密，确保产品在更新过程中的安全性。
- **高效协作与管理**: 支持多终端访问和操作，适用于需要协作和远程管理的场景。

## 优势

- **开发效率高**: 提供的标准化接口和模板减少了开发时间，使开发者可以专注于应用逻辑的实现。
- **降低开发复杂性**: 隐藏底层硬件实现的复杂性，简化与硬件交互的过程。
- **提高产品安全性和灵活性**: 通过灵活的 DFU 设计，用户可以实现自定义的安全措施，确保更新过程的完整性和安全性。
- **增强协作和管理能力**: 支持多终端访问和操作，提升设备在多用户环境中的使用效率。

AriesSDK 是一款非常高效的工具，适合需要快速开发、跨平台支持、灵活安全策略和易于维护的嵌入式项目。通过使用 AriesSDK，开发者可以显著缩短开发周期，提升产品在市场中的竞争力。

## 资源与支持

- **论坛**: [AriesSDK Forum](https://forum.umetav.cn/t/aries-sdk)  
  - **开放时间**: 北京时间每日早上8点到凌晨1点。
  
- **QQ群**: 786239575

- **技术支持邮箱**: [tech@umetav.cn](mailto:tech@umetav.cn)

请随时通过这些渠道联系我们，获取关于 AriesSDK 的更多信息或技术支持。